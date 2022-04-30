#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

const char *get_errno_error()
{
	return strerror(errno);
}

int parse_f64(const char *str, f64 *f)
{
	char *end;
	errno = 0;
	*f = strtod(str, &end);
	if (*end) // Avoid 0.123xxx as a valid number
		errno = EINVAL;
	return -(errno != 0);
}

int parse_u32(const char *str, u32 *u)
{
	u64 n;
	char *end;
	errno = 0;
	n = strtoul(str, &end, 10);
	if (*end) // Avoid 123xxx as a valid number
		errno = EINVAL;
	else if (n > UINT_MAX) // Avoid overflow
		errno = ERANGE;
	*u = n;
	return -(errno != 0);
}

int print_error(const char *context, const char *message)
{
	fprintf(stderr, "error: %s: %s\n", context, (message ? message : get_errno_error()));
	return 1;
}
