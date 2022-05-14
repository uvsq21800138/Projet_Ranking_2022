#include <assert.h>
#include <float.h>
#include <string.h>
#include "frange.h"
#include "macros.h"

frange *frange_copy(frange *dst, const frange *src)
{
	return memcpy(dst, src, sizeof(frange));
}

void frange_init(frange *r, f64 begin, f64 end, f64 step)
{
	assert(step > 0);
	r->begin = begin;
	r->end = end;
	r->step = step;
	if (begin > end)
		SWAP(begin, end);
	r->count = ((end + FLT_EPSILON - begin) / step) + 1;
}

int frange_has_next(const frange *r)
{
	return r->count > 0;
}

f64 frange_next(frange *r)
{
	assert(r->count);
	f64 f = r->begin;
	r->begin += r->step;
	--r->count;
	return f;
}
