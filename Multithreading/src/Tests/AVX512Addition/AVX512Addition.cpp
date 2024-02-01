#include "AVX512Addition.h"
#include <cassert>
#include <intrin.h>

void AVX512Addition::Execute(const float* a, const float* b, float* r, size_t size)
{
	assert(size % 16 == 0);
	for (int i = 0; i < size; i += 16) {
		__m512 A = _mm512_load_ps(&a[i]);
		__m512 B = _mm512_load_ps(&b[i]);
		__m512 R = _mm512_add_ps(A, B);
		_mm512_store_ps(&r[i], R);
	}
}
