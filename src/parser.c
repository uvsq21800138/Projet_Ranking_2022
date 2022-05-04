#include <stdlib.h>
#include "parser.h"
#include "utils.h"

FILE *parse_file(const char *path, const char *mode, int *ec)
{
	FILE *file = fopen(path, mode);
	if (!file)
		(*ec) += print_error(path, NULL);
	return file;
}

u32 parse_number_of_subgraphs(const char *arg, int *ec)
{
	u32 n;
	if (parse_u32(arg, &n) < 0)
		(*ec) += print_error(arg, NULL);
	else if (!n)
		(*ec) += print_error(arg, "The number of subgraphs must be positive.");
	return n;
}

f64 parse_ratio(const char *arg, int *ec)
{
	f64 r;
	if (parse_f64(arg, &r) < 0)
		(*ec) += print_error(arg, NULL);
	else if (r < 0 || r > 1)
		(*ec) += print_error(arg, "The value must be between 0 and 1.");
	return r;
}

matrix *parse_matrix(const char *path, FILE *file, int *ec)
{
	if (!file)
		return NULL;
	puts("Loading graph...");
	matrix *m = matrix_init_from_file(file);
	if (!m)
		(*ec) += print_error(path, NULL);
	return m;
}
