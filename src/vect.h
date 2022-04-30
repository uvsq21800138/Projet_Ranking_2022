#pragma once
#include <stdio.h>
#include "types.h"

/**
 * Adds a floating point number to each element of a vector.
 * @param v The vector.
 * @param n The size of the vector.
 * @param f The floating point number to add.
 */
void vect_add_f64(f64 *v, usize n, f64 f);

/**
 * Adds a vector to another vector.
 * @param r The result vector.
 * @param v The vector to add.
 * @param n The size of both vectors.
 */
void vect_add(f64 *r, const f64 *v, usize n);

/**
 * Performs the following operation:
 * v = v * f + g.
 * @param v The result vector.
 * @param f The floating point number to multiply with.
 * @param g The floating point number to add.
 * @param n The size of the vector.
 */
void vect_mul_add_f64(f64 *v, usize n, f64 f, f64 g);

/**
 * Multiplies a vector by a floating point number.
 * @param v The vector.
 * @param n The size of the vector.
 * @param f The floating point number to multiply.
 */
void vect_mul_f64(f64 *v, usize n, f64 f);

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
