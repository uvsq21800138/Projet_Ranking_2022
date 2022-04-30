#include <stdlib.h>
#include <time.h>
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
		"Usage: %s <input_file> <output_file> <n> <r> <alpha>...\n"
		"  <input_file>   The file where the graph is stored.\n"
		"  <output_file>  The file where the results will be stored.\n"
		"  <n>            The number of subgraphs to generate.\n"
		"  <r>            The ratio of the number of vertices to remove.\n"
		"  <alpha>...     The alpha values to use\n\n"
		"Example: %s graph.txt data.csv 10 0.5 0.8 0.85 0.9\n"
		"  -> Generates 10 subgraphs from the graph.txt file by removing half of the vertices\n"
		"  -> Then it will run PageRank for the following alpha values: 0.8 0.85 and 0.9\n"
		"  -> The results will be stored in data.csv\n"
		"  -> Each line contains the following informations:\n"
		"     pagerank_iterations, proportion_of_removed_vertices, proportion_of_removed_edges, number_of_empty_pages, iterations_alpha_1, iterations_alpha_2...\n",
		binary_name, binary_name);
	return EXIT_FAILURE;
}
/**
 * Generates the output file.
 * @param output_file The file where the results will be stored.
 * @param m The matrix of the orginal graph.
 * @param n The number of subgraphs to generate.
 * @param removed_vertices_count The number of vertices to remove.
 * @param alpha_values The alpha values to use.
 * @param alpha_values_count The number of alpha values.
 */
static void generate_data(FILE *output_file, const matrix *m, u32 n, u32 removed_vertices_count, const f64 *alpha_values, usize alpha_values_count)
{
	u32 vc = m->vertices_count;
	usize init_pi_memb_size = vc * sizeof(f64);
	usize init_pi_size = alpha_values_count * init_pi_memb_size;
	usize pi_size = (vc - removed_vertices_count) * sizeof(f64);

	f64 *init_pi = malloc(init_pi_size);
	f64 *pi = malloc(pi_size);
	matrix *subgraph = matrix_init(vc, m->edges_count);
	bitset *removed_set = malloc(bitset_size(vc) * sizeof(*removed_set));

	printf("Generating %u subgraphs with %u removed vertices...\n", n, removed_vertices_count);
	if (init_pi && pi && subgraph && removed_set)
	{
		srandom(time(NULL));

		// We compute the initial PageRank for each alpha value
		vect_set(init_pi, alpha_values_count * vc, 1.0 / vc);
		s32 pagerank_iterations;
		for (usize i = 0; i < alpha_values_count; ++i)
			pagerank_iterations = pagerank(m, alpha_values[i], EPSILON, init_pi + i * vc);

		// Then we generate n subgraphs and compute their PageRank for each alpha value
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
			fprintf(output_file, "%d, %lg, %lg, %u", pagerank_iterations,
				(f64)removed_vertices_count / vc,
				(f64)(m->edges_count - subgraph->edges_count) / m->edges_count, number_of_empty_pages);
			for (usize j = 0; j < alpha_values_count; ++j)
			{
				const f64 *t = init_pi + j * vc;
				// Sum of non removed vertices
				f64 s = 0;
				for (u32 j = 0; j < vc; ++j)
					if (!bitset_is_set(removed_set, j))
						s += t[j];
				// Normalization
				for (u32 j = 0, k = 0; j < vc; ++j)
					if (!bitset_is_set(removed_set, j))
						pi[k++] = t[j] / s;
				// Computes PageRank using the custom initial vector
				s32 iterations = pagerank(subgraph, alpha_values[j], EPSILON, pi);
				fprintf(output_file, ", %d", iterations);
			}
			fputc('\n', output_file);
			percent += percent_factor;
			printf("\r%.2lf%%", percent);
			fflush(stdout);
		}
		putchar('\n');
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
	if (ac < 6) // Not enough arguments
		return show_usage(ac ? av[0] : DEFAULT_BINARY_NAME);

	// Parse arguments
	int errors_count = 0;
	FILE *input_file = parse_file(av[1], "r", &errors_count);
	FILE *output_file = parse_file(av[2], "w", &errors_count);
	u32 n = parse_number_of_subgraphs(av[3], &errors_count);
	f64 r = parse_ratio(av[4], &errors_count);
	usize alpha_values_count = ac - 5;
	f64 *alpha_values = parse_alpha_values(av + 5, alpha_values_count, &errors_count);
	matrix *m = input_file ? parse_matrix(av[1], input_file, &errors_count) : NULL;
	u32 removed_vertices_count = m ? m->vertices_count * r : 0;

	if (m && removed_vertices_count == m->vertices_count)
		errors_count += print_error("r", "The given ratio is too high");
	if (errors_count)
		fprintf(stderr, "%d error%s found.\n", errors_count, (errors_count > 1 ? "s" : ""));
	else // We can run PageRank
		generate_data(output_file, m, n, removed_vertices_count, alpha_values, alpha_values_count);

	// Final cleanup
	if (input_file)
		fclose(input_file);
	if (output_file)
		fclose(output_file);
	free(alpha_values);
	matrix_destroy(m);

	if (errors_count)
		return EXIT_FAILURE;
}
