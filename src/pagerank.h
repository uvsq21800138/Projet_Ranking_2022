#pragma once
#include "matrix.h"
#include "vect.h"

/**
 * PageRank algorithm.
 * Stores the result in the given vector.
 * @param m The matrix to use.
 * @param alpha The damping factor.
 * @param epsilon The convergence threshold.
 * @param pi The initial vector to use.
 * @return The number of iterations needed to converge or -1 if an error occured.
 */
s64 pagerank(const matrix *m, f64 alpha, f64 epsilon, f64 *pi);
