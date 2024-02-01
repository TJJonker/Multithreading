#include "Utils/ScopedTimer/ScopedTimer.h"
#include "Utils/SSESupport/SSESupport.h"

#include <xmmintrin.h>
#include <iostream>

#include "Tests/SSEAddition/SSEAddition.h"
#include "TestingEnvironment/TestingEnvironment.h"
#include "Tests/FloatAddition/FloatAddition.h"
#include "Tests/AVXAddition/AVXAddition.h"
#include "Tests/AVX512Addition/AVX512Addition.h"

TestingEnvironment testingEnvironment;

FloatAddition floatAddition;
SSEAddition sseAddition;
AVXAddition avxAddition;

int main() {
	SSESupport::CheckSupport();

	testingEnvironment.SetTest([&](const float* a, const float* b, float* r, size_t size) { avx512Addition.Execute(a, b, r, size); });
	testingEnvironment.SetResultCheck([](const float* a, const float* b, float* r, size_t size) 
		{  
			bool success = true;
			for (int i = 0; i < size; i++)
				success &= (a[i] + b[i] == r[i]);
			
			if (success)
				std::cout << "Test Succesful!" << std::endl;
			else
				std::cout << "Test Failed..." << std::endl;
		}
	);

	testingEnvironment.RunTest();
}