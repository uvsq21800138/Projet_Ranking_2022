#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "bitset.h"
#include "macros.h"
#include "matrix.h"

/**
 * Initiliazes an edge from a stream.
 * @param e The edge to initialize.
 * @param f The file to read the row from.
 * @return 0 on success, -1 on error.
 */
static int edge_init_from_file(edge *e, FILE *f)
{
	int retv = fscanf(f, "%u %lf", &e->y, &e->w);
	--e->y;
	return retv;
}

/**
 * Initializes an edge.
 * @param e The edge to initialize.
 * @param y The vertex index.
 * @param w The weight.
 */
static void edge_init(edge *e, u32 y, f64 w)
{
	e->y = y;
	e->w = w;
}

void matrix_destroy(matrix *m)
{
	free(m);
}

int matrix_generate_subgraph(matrix *dst, const matrix *src, u32 n, bitset *removed_set)
{
	assert(n <= src->vertices_count);

	// Allocates sets
	const u32 m = src->vertices_count;
	u32 *vertices_set = malloc(m * sizeof(*vertices_set));
	u32 *edges_count_set = malloc(m * sizeof(*edges_count_set));
	if (!vertices_set || !edges_count_set)
	{
		free(vertices_set);
		free(edges_count_set);
		return -1;
	}

	// Initialize the set of vertices to remove
	for (u32 i = 0; i < m; ++i)
		vertices_set[i] = i; // All vertices are initially in the set
	// All vertices are initially not removed
	bitset_reset(removed_set, m);

	// We select vertices to remove randomly
	for (u32 i = 0; i < n; ++i)
	{
		// Removed vertices are stored on the left side of the array
		usize j = (random() % (m - i)) + i; // Selection on the right side of the array
		SWAP(vertices_set[i], vertices_set[j]);
		bitset_set(removed_set, vertices_set[i]); // Mark the vertex as removed
	}

	dst->vertices_count = m - n;
	// We have to computes the number of edges first
	const edge *it, *end;
	dst->edges_count = 0;
	for (u32 i = 0; i < m; ++i)
	{
		edges_count_set[i] = 0; // Initialize the number of edges for each vertex
		if (!bitset_is_set(removed_set, i))
			for (it = matrix_row(src, i), end = it + matrix_row_count(src, i); it < end; ++it)
				if (!bitset_is_set(removed_set, it->y))
					++edges_count_set[i];
		dst->edges_count += edges_count_set[i];
	}
	// We computes the new vertices indexes because we removed some of them (avoid gaps in our new graph)
	for (u32 i = 0, j = 0; i < m; ++i)
		if (!bitset_is_set(removed_set, i))
			vertices_set[i] = j++;
	// Then we store the new edges in the new matrix with their new normalized weights
	for (u32 i = 0, row_start_index = 0; i < m; ++i)
		if (!bitset_is_set(removed_set, i))
		{
			dst->row_start[vertices_set[i]] = row_start_index;
			edge *it2;
			for (it = matrix_row(src, i), end = it + matrix_row_count(src, i),
				it2 = dst->edges + row_start_index; it < end; ++it)
				if (!bitset_is_set(removed_set, it->y))
					edge_init(it2++, vertices_set[it->y], 1.0 / edges_count_set[i]);
			row_start_index += edges_count_set[i];
		}
	dst->row_start[dst->vertices_count] = dst->edges_count;

	// Final cleanup
	free(vertices_set);
	free(edges_count_set);
	return 0;
}

matrix *matrix_init_from_file(FILE *f)
{
	u32 vertices_count, edges_count, expected_vertex_index, vertex_index, row_start_index, i;
	matrix *m;
	if (fscanf(f, "%u %u", &vertices_count, &edges_count) < 2)
	{
		errno = EINVAL;
		return NULL;
	}
	m = matrix_init(vertices_count, edges_count);
	for (expected_vertex_index = 0, row_start_index = 0;
		expected_vertex_index < vertices_count;
		++expected_vertex_index, row_start_index += edges_count)
	{
		if (fscanf(f, "%u %u", &vertex_index, &edges_count) < 2)
			break ;
		assert(vertex_index == expected_vertex_index + 1); // Vertices indexes must be in order
		m->row_start[vertex_index - 1] = row_start_index;
		for (i = 0; i < edges_count && edge_init_from_file(m->edges + row_start_index + i, f) == 2; ++i);
		if (i < edges_count) // Invalid row
			break ;
	}
	m->row_start[vertices_count] = m->edges_count;
	if (expected_vertex_index < vertices_count) // Invalid file
	{
		errno = EINVAL;
		matrix_destroy(m);
		m = NULL;
	}
	return m;
}

matrix *matrix_init(u32 vertices_count, u32 edges_count)
{
	usize matrix_size = sizeof(matrix);
	usize edges_size = edges_count * sizeof(edge);
	usize row_start_size = (vertices_count + 1) * sizeof(u32);
	void *p = calloc(1, matrix_size + edges_size + row_start_size); // Single call allocation
	if (!p)
		return p;
	matrix *m = p;
	m->vertices_count = vertices_count;
	m->edges_count = edges_count;
	m->edges = p + matrix_size;
	m->row_start = p + matrix_size + edges_size;
	return m;
}

int matrix_print(const matrix *m, FILE *f)
{
	int r = fprintf(f, "%u\n%u\n", m->vertices_count, m->edges_count) < 0;
	for (usize i = 0; i < m->vertices_count; ++i)
	{
		const edge *t = matrix_row(m, i);
		usize n = matrix_row_count(m, i);
		r |= fprintf(f, "%lu %lu", i + 1, n) < 0;
		for (usize j = 0; j < n; ++j)
			r |= fprintf(f, " %u %lf", t[j].y + 1, t[j].w) < 0;
		r |= fputc('\n', f) == EOF;
	}
	return r;
}

const edge *matrix_row(const matrix *m, usize i)
{
	assert(i < m->vertices_count);
	return m->edges + m->row_start[i];
}

usize matrix_row_count(const matrix *m, usize i)
{
	assert(i < m->vertices_count);
	return m->row_start[i + 1] - m->row_start[i];
}
