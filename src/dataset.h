#pragma once
#include "frange.h"
#include "matrix.h"

/**
 * Clears internal dataset cache.
 */
void dataset_clear();

/**
 * Initialize internal dataset cache.
 * @param original_graph The matrix representation of the original graph.
 * @param alpha The range of alpha values.
 * @return 0 on success, -1 on error.
 */
int dataset_init(const matrix *original_graph, const frange *alpha);

/**
 * Generates the dataset.
 * @param output_file The file where the results will be stored.
 * @param n The number of subgraphs to generate.
 * @param r r The range of ratio of removed vertices to test.
 */
void generate_dataset(FILE *output_file, u32 n, const frange *r);
