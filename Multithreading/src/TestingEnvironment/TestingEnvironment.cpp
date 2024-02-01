#include "TestingEnvironment.h"
#include "../Utils/ScopedTimer/ScopedTimer.h"
#include <iostream>

#define ARRAY_SIZE 1'000'000'000

void TestingEnvironment::RunTest()
{
	std::cout << "Allocating memory for A" << std::endl;
	alignas(16) float* A = new float[ARRAY_SIZE];
	std::cout << "Allocating memory for B" << std::endl;
	alignas(16) float* B = new float[ARRAY_SIZE];
	std::cout << "Allocating memory for R" << std::endl;
	alignas(16) float* R = new float[ARRAY_SIZE];

	std::cout << "Setting data" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		A[i] = i;
		B[i] = i + 1;
	}

	std::cout << "Starting Test..." << std::endl;
	{
		ScopedTimer timer("Test completed in: ");
		m_TestFunction(&A[0], &B[0], &R[0], ARRAY_SIZE);
	}

	std::cout << "Checking results" << std::endl;
	m_CheckFunction(&A[0], &B[0], &R[0], ARRAY_SIZE);
}
