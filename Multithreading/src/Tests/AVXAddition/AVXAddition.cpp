#include "AVXAddition.h"
#include <cassert>
#include <intrin.h>

void AVXAddition::Execute(const float* a, const float* b, float* r, size_t size)
{
	assert(size % 8 == 0);
	for (int i = 0; i < size; i += 8) {
		__m256 A = _mm256_load_ps(&a[i]);
		__m256 B = _mm256_load_ps(&b[i]);
		__m256 R = _mm256_add_ps(A, B);
		_mm256_store_ps(&r[i], R);
	}
}
