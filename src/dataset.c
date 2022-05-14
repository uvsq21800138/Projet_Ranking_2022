#include <stdlib.h>
#include "dataset.h"
#include "pagerank.h"
#include "utils.h"
#include "vect.h"

#define ERASE_LINE "\033[1K\r"

static const matrix *g_original_graph = NULL;
static f64 *g_pi_cache = NULL;
static u32 *g_iter_cache = NULL;
static f64 *g_pi = NULL;
static matrix *g_subgraph = NULL;
static bitset *g_removed_set = NULL;
static const frange *g_alpha = NULL;

/**
 * Prints current progress.
 * Increments the progress counter.
 * @param percent_indicator The percentage indicator as a range.
 */
static void print_progression(frange *percent_indicator)
{
	printf(ERASE_LINE "> %6.2lf%%", 100 * frange_next(percent_indicator));
}

/**
 * Initilizes pi for custom PageRnak.
 * @param pg_pi The original PageRank vector.
 * @return The initialized vector.
 */
static f64 *init_custom_pi(const f64 *pg_pi)
{
	const u32 n = g_original_graph->vertices_count;

	// Sum of non removed vertices
	f64 s = 0;
	for (u32 j = 0; j < n; ++j)
		if (!bitset_is_set(g_removed_set, j))
			s += pg_pi[j];

	// Normalization
	for (u32 j = 0, k = 0; j < n; ++j)
		if (!bitset_is_set(g_removed_set, j))
			g_pi[k++] = pg_pi[j] / s;
	
	return g_pi;
}

void dataset_clear()
{
	pagerank_clear();
	matrix_cache_clear();
	free(g_pi_cache);
	free(g_iter_cache);
	free(g_pi);
	matrix_destroy(g_subgraph);
	free(g_removed_set);
	g_original_graph = NULL;
	g_pi_cache = NULL;
	g_iter_cache = NULL;
	g_pi = NULL;
	g_subgraph = NULL;
	g_removed_set = NULL;
	g_alpha = NULL;
}

int dataset_init(const matrix *m, const frange *alpha)
{
	if (g_original_graph)
		dataset_clear();
	usize n = m->vertices_count;
	if (pagerank_init(n) < 0 || matrix_cache_init(m) < 0)
	{
		dataset_clear();
		return -1;
	}
	g_original_graph = m;
	g_pi_cache = malloc(alpha->count * n * sizeof(f64));
	g_iter_cache = malloc(n * sizeof(u32));
	g_pi = malloc(n * sizeof(f64));
	g_subgraph = matrix_init(n, m->edges_count);
	g_removed_set = bitset_alloc(n);
	g_alpha = alpha;
	if (!g_pi_cache || !g_iter_cache || !g_pi || !g_subgraph || !g_removed_set)
	{
		dataset_clear();
		return -1;
	}

	// We compute the initial PageRank for each alpha value.
	printf("Running PageRank on original graph with %u alpha values...\n", alpha->count);
	frange a, p;
	f64 *pi = g_pi_cache;
	u32 *iter = g_iter_cache;
	frange_copy(&a, alpha);
	frange_init(&p, 0, 1, 1.0 / alpha->count);
	print_progression(&p);
	fflush(stdout);
	while (frange_has_next(&a))
	{
		vect_set(g_pi_cache, alpha->count * n, 1.0 / n);
		f64 alpha = frange_next(&a);
		*iter = pagerank(m, pi, alpha);
		print_progression(&p);
		printf(" -- alpha: %g -- iterations: %u", alpha, *iter);
		fflush(stdout);
		pi += n;
		++iter;
	}
	printf(ERASE_LINE "Done!\n");
	return 0;
}

void generate_dataset(FILE *output_file, u32 n, const frange *r)
{
	const matrix *m = g_original_graph;
	const usize vc = m->vertices_count;
	usize subgraphs_count = (usize)r->count * n;
	frange p, alpha, removed_ratio;
	frange_init(&p, 0, 1, 1.0 / (2 * subgraphs_count * g_alpha->count));
	printf("removed ratio count: %u\n", r->count);
	printf("Generating dataset with %lu subgraph%s...\n", subgraphs_count,
		(subgraphs_count > 1 ? "s": ""));
	print_progression(&p);
	fflush(stdout);
	// We generate subgraphs and compute their PageRank
	for (u32 i = 0; i < n; ++i)
	{
		frange_copy(&removed_ratio, r);
		while (frange_has_next(&removed_ratio))
		{
			f64 r = frange_next(&removed_ratio);
			matrix_generate_subgraph(g_subgraph, m, r, g_removed_set);
			usize sg_vc = g_subgraph->vertices_count;
			const f64 *original_pi = g_pi_cache;
			const u32 *original_iter = g_iter_cache;
			frange_copy(&alpha, g_alpha);
			while (frange_has_next(&alpha))
			{
				f64 a = frange_next(&alpha);
				// Computes original PageRank
				vect_set(g_pi, sg_vc, 1.0 / sg_vc);
				u32 it = pagerank(g_subgraph, g_pi, a);
				print_progression(&p);
				printf(" -- alpha: %g -- removed ratio: %g -- iterations: %u", a, r, it);
				fflush(stdout);

				// Computes custom PageRank
				u32 it2 = pagerank(g_subgraph, init_custom_pi(original_pi), a);
				print_progression(&p);
				printf(" -- alpha: %g -- removed ratio: %g -- iterations: %u", a, r, it2);
				fflush(stdout);

				// Write the results to the output file
				f64 it_acc = 1 - (f64)it2 / it;
				f64 removed_edges = (f64)(m->edges_count - g_subgraph->edges_count) / m->edges_count;
				fprintf(output_file, "%g %g %g %g\n", a, it_acc, r, removed_edges);

				original_pi += vc;
				++original_iter;
			}
		}
	}
	printf(ERASE_LINE "Done!\n");
}
