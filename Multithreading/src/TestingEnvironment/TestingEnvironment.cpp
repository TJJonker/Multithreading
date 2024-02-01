#include "TestingEnvironment.h"
#include "../Utils/ScopedTimer/ScopedTimer.h"

#define ARRAY_SIZE 10'000

void TestingEnvironment::RunTest()
{
	alignas(16) float* A = new float[ARRAY_SIZE];
	alignas(16) float* B = new float[ARRAY_SIZE];
	alignas(16) float* R = new float[ARRAY_SIZE];

	for (int i = 0; i < ARRAY_SIZE; i++) {
		A[i] = i;
		B[i] = i + 1;
	}

	{
		ScopedTimer timer("Test completed in: ");
		m_TestFunction(&A[0], &B[0], &R[0], ARRAY_SIZE);
	}

	m_CheckFunction(&A[0], &B[0], &R[0], ARRAY_SIZE);
}
