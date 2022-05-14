#include "parser.h"
#include "utils.h"

void check_range(const char *arg, f64 min_value, f64 max_value, int *ec)
{
	if (min_value > max_value)
		(*ec) += print_error(arg, "The minimum value must be less than or equal to the maximum value.");
}

FILE *parse_file(const char *path, const char *mode, int *ec)
{
	FILE *file = fopen(path, mode);
	if (!file)
		(*ec) += print_error(path, NULL);
	return file;
}

matrix *parse_matrix(const char *path, FILE *file, int *ec)
{
	if (!file)
		return NULL;
	printf("Loading file %s...\n", path);
	matrix *m = matrix_init_from_file(file);
	if (!m)
		(*ec) += print_error(path, NULL);
	return m;
}

u32 parse_non_negative(const char *arg, int *ec)
{
	u32 n;
	if (stou32(arg, &n) < 0)
		(*ec) += print_error(arg, NULL);
	else if (!n)
		(*ec) += print_error(arg, "The value must be positive.");
	return n;
}

frange parse_range(const char *arg1, const char *arg2, const char *arg3, int *ec)
{
	frange r;
	r.begin = parse_ratio(arg1, ec);
	r.end = parse_ratio(arg2, ec);
	r.step = parse_ratio(arg3, ec);
	if (!r.step)
		(*ec) += print_error(arg3, "The step size must be positive.");
	frange_init(&r, r.begin, r.end, r.step);
	return r;
}

f64 parse_ratio(const char *arg, int *ec)
{
	f64 r;
	if (stof64(arg, &r) < 0)
		(*ec) += print_error(arg, NULL);
	else if (r < 0 || r > 1)
		(*ec) += print_error(arg, "The value must be between 0 and 1.");
	return r;
}
