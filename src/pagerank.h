#pragma once
#include "matrix.h"

/**
 * PageRank algorithm.
 * Stores the result in the given vector.
 * @param m The matrix to use.
 * @param alpha The damping factor.
 * @param init_vect The initial vector to use.
 * @return The number of iterations needed to converge or -1 if an error occured.
 */
s32 pagerank(const matrix *m, f64 alpha, f64 *init_vect);
