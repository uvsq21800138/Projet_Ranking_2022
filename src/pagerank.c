#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include "pagerank.h"

/*
* Initializes f such as f[i] = 1 if the outdegree of vertex i is 0, 0 otherwise.
* @param m The matrix.
* @param f The vector to initialize.
*/
static void init_f(const matrix *m, bitset *f)
{
	for (usize i = 0; i < m->vertices_count; ++i)
		if (!matrix_row_count(m, i))
			bitset_set(f, i);
}

/**
 * Computes r = x * f'.
 * @param x The row vector.
 * @param f The bitset as a column vector.
 * @param n The size of both vectors.
 * @return The result of the multiplication as a scalar.
 */
static f64 vect_mul_cf(const f64 *x, const bitset *f, usize n)
{
	f64 r = 0.0;
	for (usize i = 0; i < n; ++i)
		if (bitset_is_set(f, i))
			r += x[i];
	return r;
}

/**
 * Computes r = x * p.
 * @param r The result vector.
 * @param x The row vector.
 * @param p The matrix.
 */
static void vect_mul_p(f64 *r, const f64 *x, const matrix *p)
{
	vect_set(r, p->vertices_count, 0);
	for (usize i = 0; i < p->vertices_count; ++i)
		for (const edge *it = matrix_row(p, i), *end = it + matrix_row_count(p, i);
			it != end; ++it)
			r[it->y] += x[i] * it->w;
}

s64 pagerank(const matrix *m, f64 alpha, f64 epsilon, f64 *init_vect)
{
	assert(IN_BOUNDS(0, alpha, 1));
	assert(IN_BOUNDS(0, epsilon, 1));

	u64 n = m->vertices_count;
	f64 *pi[2] = { init_vect, malloc(n * sizeof(f64)) };
	bitset *f = calloc(1, bitset_size(n));
	if (!pi[1] || !f)
	{
		free(pi[1]);
		free(f);
		return -1;
	}

	const f64 inv = 1.0 / n;
	s64 i = 0;
	init_f(m, f);
	do
	{
		f64 *old_pi = pi[i % 2];
		f64 *new_pi = pi[(i + 1) % 2];
		f64 s = inv * ((1 - alpha) + alpha * vect_mul_cf(old_pi, f, n));
		vect_mul_p(new_pi, old_pi, m);
		vect_mul_add_f64(new_pi, n, alpha, s);
		++i;
	}	while (vect_norm1(pi[0], pi[1], n) > epsilon);
	if (!(i % 2))
		memcpy(init_vect, pi[1], n * sizeof(*pi[1]));

	free(pi[1]);
	free(f);
	return i;
}
