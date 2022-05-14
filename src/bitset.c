#include <stdlib.h>
#include "bitset.h"
#include "macros.h"

/**
 * Returns the size of a bitset in bytes to store n bits.
 * The returned value can be used to allocate a bitset.
 * @param n The number of bits in the bitset.
 * @return The size needed to store n bits.
 */
static usize bitset_size(usize n)
{
	return n / BIT_SIZEOF(usize) + ((n % BIT_SIZEOF(usize)) != 0);
}

bitset *bitset_alloc(usize size)
{
	return malloc(bitset_size(size) * sizeof(bitset));
}

usize bitset_is_set(const bitset *bs, usize i)
{
	return bs[i / BIT_SIZEOF(usize)] & (1UL << (i % BIT_SIZEOF(usize)));
}

void bitset_set(bitset *bs, usize i)
{
	bs[i / BIT_SIZEOF(usize)] |= (1UL << (i % BIT_SIZEOF(usize)));
}

void bitset_reset(bitset *bs, usize n)
{
	n = bitset_size(n);
	for (usize i = 0; i < n; ++i)
		bs[i] = 0;
}

void bitset_unset(bitset *bs, usize i)
{
	bs[i / BIT_SIZEOF(usize)] &= ~(1UL << (i % BIT_SIZEOF(usize)));
}
