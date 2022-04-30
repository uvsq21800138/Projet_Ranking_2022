#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "bitset.h"
#include "macros.h"
#include "matrix.h"
#include "utils.h"

// Generates a new graph n removed vertices
static void generate_file(const matrix *m, FILE *graph_file, FILE *removed_set_file, u32 *vertices_set, u32 *edges_count_set, bitset *removed_set, usize n)
{
	fprintf(graph_file, "%lu\n", m->vertices_count - n); // Number of vertices
	fprintf(removed_set_file, "%lu\n", n); // Number of removed vertices
	// Initialize the set of vertices to remove
	for (usize i = 0; i < m->vertices_count; ++i)
		vertices_set[i] = i; // All vertices are initially in the set
	bitset_reset(removed_set, m->vertices_count); // All vertices are initially not removed
	// We select vertices to remove randomly
	for (usize i = 0; i < n; ++i)
	{
		// Removed vertices are stored on the left side of the array
		usize j = (random() % (m->vertices_count - i)) + i; // Selection on the right side of the array
		SWAP(vertices_set[i], vertices_set[j]);
		bitset_set(removed_set, vertices_set[i]); // Mark the vertex as removed
	}
	// We have to computes the number of edges first
	const edge *start, *end;
	usize edges_count = 0;
	for (usize i = 0; i < m->vertices_count; ++i)
	{
		edges_count_set[i] = 0; // Initialize the number of edges for each vertex
		if (bitset_is_set(removed_set, i))
			fprintf(removed_set_file, "%lu ", i + 1); // Prints the removed vertex
		else
			for (start = matrix_row(m, i), end = start + matrix_row_count(m, i); start < end; ++start)
				if (!bitset_is_set(removed_set, start->y))
					++edges_count_set[i];
		edges_count += edges_count_set[i];
	}
	fprintf(graph_file, "%lu\n", edges_count); // Number of edges
	// We computes the new vertices indexes because we removed some of them (avoid gaps in our new graph)
	for (usize i = 0, j = 0; i < m->vertices_count; ++i)
		if (!bitset_is_set(removed_set, i))
			vertices_set[i] = j++;
	// Then we print the edges for each vertex
	for (usize i = 0; i < m->vertices_count; ++i)
		if (!bitset_is_set(removed_set, i))
		{
			// We have to know the number of edges first
			fprintf(graph_file, "%u %u", vertices_set[i] + 1, edges_count_set[i]); // Vertex and number of edges
			// Then we print the edges with their new normalized weight
			for (start = matrix_row(m, i), end = start + matrix_row_count(m, i); start < end; ++start)
				if (!bitset_is_set(removed_set, start->y))
					fprintf(graph_file, " %u %lf", vertices_set[start->y] + 1, 1.0 / edges_count_set[i]);
			fputc('\n', graph_file);
		}
}

/**
 * Initiliazes an edge.
 * @param e The edge to initialize.
 * @param f The file to read the row from.
 * @return 0 on success, -1 on error.
 */
static int row_init(edge *e, FILE *f)
{
	int retv = fscanf(f, "%u %lf", &e->y, &e->w);
	--e->y;
	return retv;
}

void matrix_destroy(matrix *m)
{
	free(m);
}

void matrix_generate_dataset(const char *path, f64 r, usize n)
{
	// We try to load the matrix
	FILE *graph_file = fopen(path, "r"), *removed_set_file;
	if (!graph_file)
		exit_fatal(path);
	printf("Loading graph %s...\n", path);
	matrix *m = matrix_init_from_file(graph_file);
	fclose(graph_file);
	if (!m)
		exit_fatal("mat_init");
	// We allocates the set of vertices to remove to perform deletion in linear time
	u32 *vertices_set = malloc(m->vertices_count * sizeof(*vertices_set));
	u32 *edges_count_set = malloc(m->vertices_count * sizeof(*edges_count_set));
	bitset *removed_set = malloc(bitset_size(m->vertices_count) * sizeof(*removed_set));
	// Dataset filenames are generated from the given path
	char *ext = rindex(path, '.');
	if (!ext)
		ext = "";
	usize path_len = strlen(path), ext_len = strlen(ext);
	char *output_path = malloc(path_len + 64);
	if (!vertices_set || !edges_count_set || !removed_set || !output_path)
		exit_fatal("malloc");
	// We generate the dataset of n subgraphs
	printf("Generating %lu graph%s with %lu removed vertices...\n", n, (n > 1 ? "s" : ""),
	(usize)(m->vertices_count * r));
	for (usize i = 1; i <= n; ++i)
	{
		sprintf(output_path, "%.*s_%.2lf_%lu%s", (int)(path_len - ext_len), path, r, i, ext);
		graph_file = fopen(output_path, "w");
		if (!graph_file)
			exit_fatal(output_path);
		printf("Writing to %s...\n", output_path);
		sprintf(output_path, "%.*s_%.2lf_%lu_removed_set_%s", (int)(path_len - ext_len), path, r, i, ext);
		removed_set_file = fopen(output_path, "w");
		if (!graph_file)
			exit_fatal(output_path);
		generate_file(m, graph_file, removed_set_file, vertices_set, edges_count_set, removed_set, r * m->vertices_count);
		fclose(graph_file);
		fclose(removed_set_file);
	}
	// Final cleanup
	free(vertices_set);
	free(edges_count_set);
	free(removed_set);
	matrix_destroy(m);
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
		m->row_start[vertex_index] = row_start_index + edges_count;
		for (i = 0; i < edges_count && row_init(m->edges + row_start_index + i, f) == 2; ++i);
		if (i < edges_count) // Invalid row
			break ;
	}
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
