#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "constants.h"
#include "pagerank.h"
#include "parser.h"
#include "vect.h"
#include "utils.h"

/**
 * Prints a usage message.
 * @param binary_name The name of the binary.
 * @return Always EXIT_FAILURE.
 */
static int show_usage(const char *binary_name)
{
	fprintf(stderr,
		"Usage: %s <input_file> <output_file> <n> <r> <alpha>\n"
		"  <input_file>   The file where the graph is stored.\n"
		"  <output_file>  The file where the results will be stored.\n"
		"  <n>            The number of subgraphs to generate.\n"
		"  <r>            The ratio of the number of vertices to remove.\n"
		"  <alpha>        The alpha value to use\n\n"
		"Example: %s graph.txt output.data 10 0.5 0.85\n"
		"  -> Generates 10 subgraphs from the graph.txt file by removing half of the vertices\n"
		"  -> Then it will run PageRank for the following alpha values: 0.85\n"
		"  -> The results will be stored in output.data\n"
		"  -> Each line contains the following informations:\n"
		"     alpha pagerank_iterations custom_pagerank_iterations proportion_of_removed_vertices proportion_of_removed_edges proportion_of_empty_pages\n",
		binary_name, binary_name);
	return EXIT_FAILURE;
}

/**
 * Generates the output file.
 * @param output_file The file where the results will be stored.
 * @param m The matrix of the orginal graph.
 * @param n The number of subgraphs to generate.
 * @param removed_vertices_count The number of vertices to remove.
 * @param alpha The alpha values to use.
 */
static void generate_data(FILE *output_file, const matrix *m, u32 n, u32 removed_vertices_count, f64 alpha)
{
	u32 vc = m->vertices_count;
	usize init_pi_size = vc;
	usize pi_size = vc - removed_vertices_count;

	f64 *init_pi = malloc(init_pi_size * sizeof(f64));
	f64 *pi = malloc(pi_size * sizeof(f64));
	matrix *subgraph = matrix_init(vc, m->edges_count);
	bitset *removed_set = malloc(bitset_size(vc) * sizeof(*removed_set));

	printf("Generating %u subgraphs with %u removed vertices...\n", n, removed_vertices_count);
	if (init_pi && pi && subgraph && removed_set)
	{
		srandom(time(NULL) + getpid());

		// We compute the initial PageRank
		vect_set(init_pi, vc, 1.0 / vc);
		s32 pagerank_iterations = pagerank(m, alpha, EPSILON, init_pi);

		// Then we generate n subgraphs and compute their PageRank
		f64 percent_factor = 100.0 / n;
		f64 percent = 0;
		for (u32 i = 0; i < n; ++i)
		{
			if (matrix_generate_subgraph(subgraph, m, removed_vertices_count, removed_set) < 0)
			{
				print_error("matrix_generate_subgraph", NULL);
				break ;
			}
			u32 number_of_empty_pages = 0;
			for (u32 j = 0; j < subgraph->vertices_count; ++j)
				if (!matrix_row_count(subgraph, j))
					++number_of_empty_pages;
			// Sum of non removed vertices
			f64 s = 0;
			for (u32 j = 0; j < vc; ++j)
				if (!bitset_is_set(removed_set, j))
					s += init_pi[j];
			// Normalization
			for (u32 j = 0, k = 0; j < vc; ++j)
				if (!bitset_is_set(removed_set, j))
					pi[k++] = init_pi[j] / s;
			// Computes PageRank using the custom initial vector
			s32 iterations = pagerank(subgraph, alpha, EPSILON, pi);
			// Write the results to the output file
			fprintf(output_file, "%lg %d %d %lg %lg %lg\n", alpha, pagerank_iterations,
				iterations, (f64)removed_vertices_count / vc,
				(f64)(m->edges_count - subgraph->edges_count) / m->edges_count,
				(f64)number_of_empty_pages / subgraph->vertices_count);
			// Prints the progress indicator
			percent += percent_factor;
			printf("\r%.2lf%%", percent);
			fflush(stdout);
		}
		puts("\rDone!  ");
	}
	else
		print_error("generate_data", NULL);

	free(init_pi);
	free(pi);
	free(subgraph);
	free(removed_set);
}

int main(int ac, char **av)
{
	if (ac != 6) // Not enough arguments
		return show_usage(ac ? av[0] : DEFAULT_BINARY_NAME);

	// Parse arguments
	int errors_count = 0;
	FILE *input_file = parse_file(av[1], "r", &errors_count);
	FILE *output_file = parse_file(av[2], "a", &errors_count);
	u32 n = parse_number_of_subgraphs(av[3], &errors_count);
	f64 r = parse_ratio(av[4], &errors_count);
	f64 alpha = parse_ratio(av[5], &errors_count);
	matrix *m = input_file ? parse_matrix(av[1], input_file, &errors_count) : NULL;
	u32 removed_vertices_count = m ? m->vertices_count * r : 0;

	if (m && removed_vertices_count == m->vertices_count)
		errors_count += print_error("r", "The given ratio is too high");
	if (errors_count)
		fprintf(stderr, "%d error%s found.\n", errors_count, (errors_count > 1 ? "s" : ""));
	else // We can run PageRank
		generate_data(output_file, m, n, removed_vertices_count, alpha);

	// Final cleanup
	if (input_file)
		fclose(input_file);
	if (output_file)
		fclose(output_file);
	matrix_destroy(m);

	if (errors_count)
		return EXIT_FAILURE;
}
