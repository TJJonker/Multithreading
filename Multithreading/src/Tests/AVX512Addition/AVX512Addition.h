#pragma once
#include "../ITest.h"

class AVX512Addition : public ITest
{
public:
	void Execute(const float*, const float*, float*, size_t) override;
};

