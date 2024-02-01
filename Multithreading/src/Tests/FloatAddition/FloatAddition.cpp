#include "FloatAddition.h"

void FloatAddition::Execute(float* a, float* b, float* r, size_t size)
{
	for (int i = 0; i < size; ++i) {
		r[i] = a[i] + b[i];
	}
}
