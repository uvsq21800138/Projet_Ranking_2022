#pragma once
#include "types.h"

/** A memory-efficient representation of an array of bits. */
typedef usize bitset;

/**
 * Allocates memory for a bitset.
 * The bitset is not initialized.
 * @param size The number of bits in the bitset.
 * @return The allocated bitset or NULL if the allocation failed.
 */
bitset *bitset_alloc(usize size);

/**
 * Checks if a bit is set in a bitset.
 * @param bs The bitset.
 * @param i The index of the bit to check.
 * @return A non zero value if the bit at index i is set, 0 otherwise.
 */
usize bitset_is_set(const bitset *bs, usize i);

/**
 * Sets a bit in a bitset.
 * @param bs The bitset.
 * @param i The index of the bit to set.
 */
void bitset_set(bitset *bs, usize i);

/**
 * Resets all bits of a bitset of n bits.
 * @param bs The bitset.
 * @param n The number of bits.
 */
void bitset_reset(bitset *bs, usize n);

/**
 * Unsets a bit in a bitset.
 * @param bs The bitset.
 * @param i The index of the bit to unset.
 */
void bitset_unset(bitset *bs, usize i);
