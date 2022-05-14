#include <string.h>
#include "vect.h"

f64 *vect_copy(f64 *dst, const f64 *src, usize n)
{
	return memcpy(dst, src, n * sizeof(f64));
}

void vect_mul_add_f64(f64 *v, usize n, f64 f, f64 g)
{
	for (usize i = 0; i < n; ++i)
		v[i] = v[i] * f + g;
}

f64 vect_norm1(const f64 *v, const f64 *w, usize n)
{
	f64 r = 0;
	for (usize i = 0; i < n; ++i)
		if (v[i] > w[i])
			r += v[i] - w[i];
		else
			r += w[i] - v[i];
	return r;
}

int vect_print(const f64 *v, usize n, FILE *f)
{
	int r = fputc('[', f) == EOF;
	if (n)
		r |= fprintf(f, "%lf", *v) < 0;
	for (usize i = 1; i < n; ++i)
		r |= fprintf(f, " %lf", v[i]) < 0;
	r |= fputs("]\n", f) < 0;
	return r;
}

void vect_set(f64 *v, usize n, f64 f)
{
	for (usize i = 0; i < n; ++i)
		v[i] = f;
}
