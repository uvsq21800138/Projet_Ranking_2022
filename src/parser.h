#pragma once
#include <stdio.h>
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
 * Parse the number of subgraphs to generate.
 * @param arg The argument to parse.
 * @param ec The errors counter.
 * @return The number of subgraphs to generate.
 */
u32 parse_number_of_subgraphs(const char *arg, int *ec);

/**
 * Parse the ratio of the number of vertices to remove.
 * @param arg The argument to parse.
 * @param ec The errors counter.
 * @return The ratio of the number of vertices to remove.
 */
f64 parse_ratio(const char *arg, int *ec);

/**
 * Parse the alpha values to use.
 * Allocates the array and increments the errors counter if an error occured.
 * The array must be freed by the caller.
 * @param args The arguments to parse.
 * @param n The number of arguments.
 * @param ec The errors counter.
 * @return An array of alpha values to use or NULL if an error occured.
 */
f64 *parse_alpha_values(char * const *args, usize n, int *ec);

/**
 * Parse the graph file.
 * @param path The original path of the file.
 * @param file The file to parse.
 * @param ec The errors counter.
 * @return The loaded graph or NULL if an error occured.
 */
matrix *parse_matrix(const char *path, FILE *file, int *ec);
