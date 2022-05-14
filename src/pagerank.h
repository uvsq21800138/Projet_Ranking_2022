#pragma once
#include "matrix.h"

/** The convergence threshold for the PageRank algorithm. */
#define PAGERANK_EPSILON 1e-6

/**
 * Clears internal PageRank cache.
 */
void pagerank_clear();

/**
 * Initialize internal PageRank cache.
 * @param n The maximum number of vertices.
 * @return 0 on success, -1 on error.
 */
int pagerank_init(u64 n);

/**
 * PageRank algorithm.
 * pagerank_init() must be called before this function.
 * Stores the result in the given vector.
 * @param m The matrix to use.
 * @param init_vect The initial vector to use.
 * @param alpha The damping factor.
 * @return The number of iterations needed to converge.
 */
u32 pagerank(const matrix *m, f64 *init_vect, f64 alpha);
