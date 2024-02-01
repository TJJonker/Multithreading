#include "SSEAddition.h"
#include <intrin.h>
#include <cassert>

void SSEAddition::Execute(const float* a, const float* b, float* r, size_t size)
{
	assert(size % 4 == 0);
	for (unsigned int i = 0; i < size; i += 4) {
		__m128 A = _mm_load_ps(&a[i]);
		__m128 B = _mm_load_ps(&b[i]);
		__m128 R = _mm_add_ps(A, B);
		_mm_store_ps(&r[i], R);
	}
}
