#pragma once
#include "../ITest.h"

class FloatAddition : public ITest
{
public:
	void Execute(float*, float*, float*, size_t) override;
};

