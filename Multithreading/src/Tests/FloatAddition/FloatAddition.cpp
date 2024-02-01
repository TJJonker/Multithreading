#include "FloatAddition.h"

void FloatAddition::Execute(const float* a, const float* b, float* r, size_t size)
{
	for (int i = 0; i < size; ++i) {
		r[i] = a[i] + b[i];
	}
}
