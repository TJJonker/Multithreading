#include "ScopedTimer.h"
#include "SSESupport.h"

#include <xmmintrin.h>

void TestAddSSE();

int main() {
	SSESupport::CheckSupport();
	
	//TestAddSSE();
}

void TestAddSSE() {
	alignas(16) float A[4];
	alignas(16) float B[4] = { 2.f, 4.f, 6.f, 8.f };

	__m128 a = _mm_set_ps(4.f, 3.f, 2.f, 1.f);
	__m128 b = _mm_load_ps(&B[0]);

	__m128 r = _mm_add_ps(a, b);
	
	_mm_store_ps(&A[0], a);
	
	alignas(16) float R[4];
	_mm_store_ps(&R[0], r);

	printf("a = %.1f %.1f %.1f %.1f\n", A[0], A[1], A[2], A[3]);
	printf("b = %.1f %.1f %.1f %.1f\n", B[0], B[1], B[2], B[3]);
	printf("r = %.1f %.1f %.1f %.1f\n", R[0], R[1], R[2], R[3]);
}