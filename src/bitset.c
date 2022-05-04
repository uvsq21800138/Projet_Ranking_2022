#include "bitset.h"
#include "macros.h"

usize bitset_is_set(const bitset *bs, usize i)
{
	return bs[i / BIT_SIZEOF(usize)] & (1UL << (i % BIT_SIZEOF(usize)));
}

void bitset_set(bitset *bs, usize i)
{
	bs[i / BIT_SIZEOF(usize)] |= (1UL << (i % BIT_SIZEOF(usize)));
}

usize bitset_size(usize n)
{
	return (n / BIT_SIZEOF(usize) + ((n % BIT_SIZEOF(usize)) != 0)) * sizeof(bitset);
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
