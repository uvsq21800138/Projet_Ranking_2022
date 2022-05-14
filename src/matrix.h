#pragma once
#include <stdio.h>
#include "bitset.h"

/** An edge of the spare matrix. */
typedef struct s_edge
{
	/** Destination vertex. */
	u32 y;
	/** Weight. */
	f64 w;
} edge;

/** A spare matrix representation. */
typedef struct s_matrix
{
	/** Number of vertices. */
	u32 vertices_count;
	/** Number of edges. */
	u32 edges_count;
	/** Edges stored in a contiguous array. */
	edge *edges;
	/** Row start indices for each vertex. */
	u32 *row_start;
} matrix;

/**
 * Clears internal matrix cache.
 */
void matrix_cache_clear();

/**
 * Initialize internal matrix cache for subgraph generation.
 * @param m The original matrix.
 * @return 0 on success, -1 on error.
 */
int matrix_cache_init(const matrix *m);

/**
 * Frees a matrix.
 * If the matrix is NULL, nothing happens.
 * @param m The matrix.
 */
void matrix_destroy(matrix *m);

/**
 * Generate a subgraph based on the given matrix with n random vertices removed.
 * The dst matrix must be allocated and have enough space to store the subgraph.
 * The removed vertices are stored in the given bitset.
 * The bitset must have enough space to store the number of vertices of the src matrix.
 * @param dst The destination matrix.
 * @param src The source matrix.
 * @param r The ratio of vertices to remove.
 * @param removed_set The set of removed vertices.
 */
void matrix_generate_subgraph(matrix *dst, const matrix *src, f64 r, bitset *removed_set);

/**
 * Initializes a new matrix from a file.
 * @param f The file stream.
 * @return The new matrix or NULL if the allocation failed.
 */
matrix *matrix_init_from_file(FILE *f);

/**
 * Initializes a new matrix.
 * @param vertices_count The number of vertices.
 * @param edges_count The number of edges.
 * @return The new matrix or NULL if the allocation failed.
 */
matrix *matrix_init(u32 vertices_count, u32 edges_count);

/**
 * Prints a matrix on a file stream.
 * @param m The matrix.
 * @param f The file stream.
 * @return EOF if an error occured, 0 otherwise.
 */
int matrix_print(const matrix *m, FILE *f);

/**
 * Returns the begining of the row at the given index.
 * @param m The matrix.
 * @param i The index of the row.
 * @return The first edge of the row.
 */
const edge *matrix_row(const matrix *m, usize i);

/**
 * Returns the size of the row at the given index.
 * @param m The matrix.
 * @param i The index of the row.
 * @return The number of elements in the row.
 */
usize matrix_row_count(const matrix *m, usize i);
