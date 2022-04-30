#include <stdlib.h>
#include <time.h>
#include "pagerank.h"
#include "utils.h"

#define DEFAULT_BINARY_NAME "ranking"
#define MAX_ALPHAS_VALUES 16

/**
 * Prints an error message.
 * @param context The context of the error.
 * @param message The error message. If NULL, the last error from errno is used.
 * @return Always 1.
 */
static int print_error(const char *context, const char *message)
{
	fprintf(stderr, "error: %s: %s\n", context, (message ? message : get_errno_error()));
	return 1;
}

/**
 * Prints a usage message.
 * @param binary_name The name of the binary.
 * @return Always EXIT_FAILURE.
 */
static int show_usage(const char *binary_name)
{
	fprintf(stderr,
		"Usage: %s <file> <n> <r> <alpha>...\n"
		"  <file>      The file where the graph is stored.\n"
		"  <n>         The number of subgraphs to generate.\n"
		"  <r>         The ratio of the number of vertices to remove.\n"
		"  <alpha>...  The alpha values to use\n\n"
		"Example: %s graph.txt 10 0.5 0.8 0.85 0.9\n"
		"  -> Generates 10 subgraphs from the graph.txt file by removing half of the vertices.\n"
		"  -> Then it will run PageRank for the following alpha values: 0.8 0.85 and 0.9.",
		binary_name, binary_name);
	return EXIT_FAILURE;
}

static FILE *parse_file(const char *path, int *ec)
{
	FILE *file = fopen(path, "r");
	if (!file)
		(*ec) += print_error(path, NULL);
	return file;
}

static u32 parse_number_of_subgraphs(const char *arg, int *ec)
{
	u32 n;
	if (parse_u32(arg, &n) < 0)
		(*ec) += print_error(arg, NULL);
	else if (!n)
		(*ec) += print_error(arg, "The number of subgraphs must be positive.");
	return n;
}

static f64 parse_ratio(const char *arg, int *ec)
{
	f64 r;
	if (parse_f64(arg, &r) < 0)
		(*ec) += print_error(arg, NULL);
	else if (r < 0 || r > 1)
		(*ec) += print_error(arg, "The ratio must be between 0 and 1.");
	return r;
}

static f64 *parse_alpha_values(char * const *args, usize n, int *ec)
{
	const char *var_name = "alphas";
	f64 *alpha_values = NULL;
	if (n > MAX_ALPHAS_VALUES)
		(*ec) += print_error(var_name, "Too many alpha values.");
	else
	{
		alpha_values = malloc(n * sizeof(*alpha_values));
		if (alpha_values)
		{
			for (usize i = 0; i < n; ++i)
			{
				if (parse_f64(args[i], alpha_values + i) < 0)
					(*ec) += print_error(args[i], NULL);
				else if (alpha_values[i] < 0 || alpha_values[i] > 1)
					(*ec) += print_error(args[i], "The alpha value must be between 0 and 1.");
			}
		}
		else
			(*ec) += print_error(var_name, NULL);
	}
	return alpha_values;
}

static matrix *parse_matrix(const char *path, FILE *file, int *ec)
{
	if (!file)
		return NULL;
	matrix *m = matrix_init_from_file(file);
	if (!m)
		(*ec) += print_error(path, NULL);
	return m;
}

int main(int ac, char **av)
{
	if (ac < 5) // Not enough arguments
		return show_usage(ac ? av[0] : DEFAULT_BINARY_NAME);
	
	// Parse arguments
	int errors_count = 0;
	FILE *file = parse_file(av[1], &errors_count);
	u32 n = parse_number_of_subgraphs(av[2], &errors_count);
	f64 r = parse_ratio(av[3], &errors_count);
	f64 *alpha_values = parse_alpha_values(av + 4, ac - 4, &errors_count);
	matrix *m = parse_matrix(av[1], file, &errors_count);

	if (errors_count)
		fprintf(stderr, "%d error%s found.\n", errors_count, (errors_count > 1 ? "s" : ""));
	else // We can run PageRank
	{
		srandom(time(NULL));
		//matrix_print(m, stdout);
		(void)n;
		(void)r;
		f64 *pi = malloc(m->vertices_count * sizeof(*pi));
		vect_set(pi, m->vertices_count, 1.0 / m->vertices_count);
		s64 iterations = pagerank(m, 0.85, 1e-6, pi);
		printf("iterations: %ld\n", (long)iterations);
		free(pi);
	}

	// Final cleanup
	if (file)
		fclose(file);
	free(alpha_values);
	matrix_destroy(m);

	if (errors_count)
		return EXIT_FAILURE;
}
