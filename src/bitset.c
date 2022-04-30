#include <limits.h>
#include "bitset.h"

#define WORD_SIZE (sizeof(usize) * CHAR_BIT)

usize bitset_is_set(const bitset *bs, usize i)
{
	return bs[i / WORD_SIZE] & (1UL << (i % WORD_SIZE));
}

void bitset_set(bitset *bs, usize i)
{
	bs[i / WORD_SIZE] |= (1UL << (i % WORD_SIZE));
}

usize bitset_size(usize n)
{
	return (n / WORD_SIZE + ((n % WORD_SIZE) != 0)) * sizeof(bitset);
}

void bitset_reset(bitset *bs, usize n)
{
	n = bitset_size(n);
	for (usize i = 0; i < n; ++i)
		bs[i] = 0;
}

void bitset_unset(bitset *bs, usize i)
{
	bs[i / WORD_SIZE] &= ~(1UL << (i % WORD_SIZE));
}
