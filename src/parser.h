#pragma once
#include "frange.h"
#include "matrix.h"

/**
 * Try to open a file.
 * Increments the errors counter if an error occured.
 * @param path The path of the file.
 * @param mode The mode to open the file.
 * @param ec The errors counter.
 * @return The opened file or NULL if an error occured.
 */
FILE *parse_file(const char *path, const char *mode, int *ec);

/**
 * Parse the graph file.
 * Increments the errors counter if an error occured.
 * @param path The original path of the file.
 * @param file The file to parse.
 * @param ec The errors counter.
 * @return The loaded graph or NULL if an error occured.
 */
matrix *parse_matrix(const char *path, FILE *file, int *ec);

/**
 * Parse a non negative integer.
 * Increments the errors counter if an error occured.
 * @param arg The argument to parse.
 * @param ec The errors counter.
 * @return The parsed integer.
 */
u32 parse_non_negative(const char *arg, int *ec);

/**
 * Parse a range of floating point numbers.
 * Increments the errors counter if an error occured.
 * @param arg1 The beginning of the range.
 * @param arg2 The end of the range.
 * @param arg3 The number of steps in the range.
 * @param ec The errors counter.
 * @return The parsed range.
 */
frange parse_range(const char *arg1, const char *arg2, const char *arg3, int *ec);

/**
 * Parse the ratio of the number of vertices to remove.
 * Increments the errors counter if an error occured.
 * @param arg The argument to parse.
 * @param ec The errors counter.
 * @return The ratio of the number of vertices to remove.
 */
f64 parse_ratio(const char *arg, int *ec);
