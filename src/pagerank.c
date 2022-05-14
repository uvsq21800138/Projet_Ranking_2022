#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include "pagerank.h"
#include "vect.h"

static f64 *g_pi_cache = NULL;
static bitset *g_f_cache = NULL;
static usize g_pi_cache_size = 0;

/*
* Initializes f such as f[i] = 1 if the outdegree of vertex i is 0, 0 otherwise.
* @param m The matrix.
* @param f The vector to initialize.
*/
static void init_f(const matrix *m, bitset *f)
{
	bitset_reset(f, m->vertices_count);
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
	f64 r = 0;
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

void pagerank_clear()
{
	free(g_pi_cache);
	free(g_f_cache);
	g_pi_cache = NULL;
	g_f_cache = NULL;
	g_pi_cache_size = 0;
}

int pagerank_init(u64 n)
{
	if (g_pi_cache)
		pagerank_clear();
	g_pi_cache = malloc(n * sizeof(f64));
	g_f_cache = bitset_alloc(n);
	g_pi_cache_size = n;
	if (!g_pi_cache || !g_f_cache)
	{
		pagerank_clear();
		return -1;
	}
	return 0;
}

u32 pagerank(const matrix *m, f64 *init_vect, f64 alpha)
{
	assert(g_pi_cache);
	assert(g_f_cache);
	assert(m->vertices_count <= g_pi_cache_size);
	assert(IN_BOUNDS(0, alpha, 1));
	assert(IN_BOUNDS(0, PAGERANK_EPSILON, 1));

	u64 n = m->vertices_count;
	f64 *pi[2] = { init_vect, g_pi_cache };
	bitset *f = g_f_cache;

	init_f(m, f);
	vect_set(pi[1], n, 0);
	u32 i = 0;
	do
	{
		f64 *old_pi = pi[i % 2];
		f64 *new_pi = pi[(i + 1) % 2];
		f64 s = (1.0 / n) * ((1 - alpha) + alpha * vect_mul_cf(old_pi, f, n));
		vect_mul_p(new_pi, old_pi, m);
		vect_mul_add_f64(new_pi, n, alpha, s);
		++i;
	}	while (vect_norm1(*pi, pi[1], n) > PAGERANK_EPSILON);
	if (!(i % 2))
		vect_copy(init_vect, pi[1], n);
	return i;
}
