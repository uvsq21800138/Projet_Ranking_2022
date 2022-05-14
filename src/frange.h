#pragma once
#include "types.h"

/** A range datatype to iterate over a range of floating point numbers. */
typedef struct s_frange
{
	/** The first value in the range. */
	f64 begin;
	/** The last value in the range (inclusive). */
	f64 end;
	/** The step size. */
	f64 step;
	/** The number of values in the range. */
	u32 count;
} frange;

/**
 * Copys a range.
 * @param dst The destination range.
 * @param src The range to copy.
 * @return The destination range.
 */
frange *frange_copy(frange *dst, const frange *src);

/**
 * Initializes a range.
 * @param r The range to initialize.
 * @param begin The beginning of the range.
 * @param end The end of the range.
 * @param step The step size.
 */
void frange_init(frange *r, f64 begin, f64 end, f64 step);

/**
 * Checks if a range is still valid.
 * @param r The range to check.
 * @return The number of steps remaining in the range.
 */
int frange_has_next(const frange *r);

/**
 * Iterates over a range.
 * The range is modified in-place.
 * @param r The range to iterate over.
 * @return The next value in the range.
 */
f64 frange_next(frange *r);
