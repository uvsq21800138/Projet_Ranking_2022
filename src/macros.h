#pragma once

/**
 * Checks if a number is in a range.
 * @param MIN The minimum value of the range.
 * @param MAX The maximum value of the range.
 * @param X The number to check.
 * @return 1 if X is in the range [MIN, MAX], 0 otherwise.
 */
#define IN_BOUNDS(MIN, X, MAX) ((X) >= (MIN) && (X) <= (MAX))

/**
 * Swap the content of two variables.
 * @param A The first variable.
 * @param B The second variable.
 */
#define SWAP(A, B) \
	do { \
		typeof((A)) C = (A); \
		(A) = (B); \
		(B) = C; \
	} while (0)
