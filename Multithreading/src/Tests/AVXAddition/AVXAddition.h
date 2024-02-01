#pragma once
#include "../ITest.h"

class AVXAddition : public ITest
{
public:
	void Execute(const float*, const float*, float*, size_t) override;
};

