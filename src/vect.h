#pragma once
#include <stdio.h>
#include "types.h"

/**
 * Copys a vector.
 * @param dst The destination vector.
 * @param src The vector to copy.
 * @param n The size of both vectors.
 * @return The destination vector.
 */
f64 *vect_copy(f64 *dst, const f64 *src, usize n);

/**
 * Performs the following operation:
 * v = v * f + g.
 * @param v The result vector.
 * @param n The size of the vector.
 * @param f The floating point number to multiply with.
 * @param g The floating point number to add.
 */
void vect_mul_add_f64(f64 *v, usize n, f64 f, f64 g);

/**
 * Computes the 1-norm of two vectors.
 * @param v The first vector.
 * @param w The second vector.
 * @param n The size of both vectors.
 * @return The 1-norm of the two vectors.
 */
f64 vect_norm1(const f64 *v, const f64 *w, usize n);

/**
 * Prints a vector on a file stream.
 * @param v The vector.
 * @param n The size of the vector.
 * @param f The file stream.
 * @return EOF if an error occured, 0 otherwise.
 */
int vect_print(const f64 *v, usize n, FILE *f);

/**
 * Sets all elements of a vector to a floating point number.
 * @param v The vector.
 * @param n The size of the vector.
 * @param f The floating point number to set.
 */
void vect_set(f64 *v, usize n, f64 f);
