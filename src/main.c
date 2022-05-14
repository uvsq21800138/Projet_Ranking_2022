#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "dataset.h"
#include "pagerank.h"
#include "parser.h"
#include "utils.h"

/**
 * Prints a usage message.
 * @param binary_name The name of the binary.
 * @return Always EXIT_FAILURE.
 */
static int show_usage(const char *binary_name)
{
	fprintf(stderr,
		"Usage: %s <input_file> <output_file> <n> <alpha_min> <alpha_max> <alpha_step> <r_min> <r_max> <r_step>\n"
		"  <input_file>   The file where the graph is stored.\n"
		"  <output_file>  The file where the results will be stored.\n"
		"  <n>            The sample size.\n"
		"  <alpha_min>    The minimum alpha value to use.\n"
		"  <alpha_max>    The maximum alpha value to use (inclusive).\n"
		"  <alpha_step>   The step size for each alpha value.\n"
		"  <r_min>        The minimum ratio of the number of vertices to remove.\n"
		"  <r_max>        The maximum ratio of the number of vertices to remove (inclusive).\n"
		"  <r_step>       The step size for each ratio.\n\n"
		"Example: %s graph.txt output.data 10 0.85 0.95 0.05 0.5 0.5 1\n"
		"  -> Generates 10 subgraphs from the graph.txt file by removing half of the vertices\n"
		"  -> Then it will run PageRank for the following alpha values: 0.85 0.9 0.95\n"
		"  -> The results will be stored in output.data\n"
		"  -> Each line contains the following informations:\n"
		"     alpha pagerank_iterations_acceleration proportion_of_removed_vertices proportion_of_removed_edges\n",
		binary_name, binary_name);
	return EXIT_FAILURE;
}

int main(int ac, char **av)
{
	if (ac != 10) // Not enough arguments
		return ac ? show_usage(*av) : EXIT_FAILURE;

	// Initializes the random number generator
	srandom(time(NULL) + getpid()); // Avoid same seed

	// Parse arguments
	int errors_count = 0;
	FILE *input_file = parse_file(av[1], "r", &errors_count);
	FILE *output_file = parse_file(av[2], "w", &errors_count);
	u32 n = parse_non_negative(av[3], &errors_count);
	frange alpha = parse_range(av[4], av[5], av[6], &errors_count);
	frange r = parse_range(av[7], av[8], av[9], &errors_count);
	matrix *m = input_file && !errors_count ? parse_matrix(av[1], input_file, &errors_count) : NULL;
	if (m && m->vertices_count * r.end == m->vertices_count)
		errors_count += print_error(av[8], "The given ratio is too high");

	if (errors_count)
		fprintf(stderr, "%d error%s found.\n", errors_count, (errors_count > 1 ? "s" : ""));
	else if (dataset_init(m, &alpha) < 0)
		print_error("dataset_init", NULL);
	else // We can run PageRank
		generate_dataset(output_file, n, &r);

	// Final cleanup
	dataset_clear();
	if (input_file)
		fclose(input_file);
	if (output_file)
		fclose(output_file);
	matrix_destroy(m);

	if (errors_count)
		return EXIT_FAILURE;
}
