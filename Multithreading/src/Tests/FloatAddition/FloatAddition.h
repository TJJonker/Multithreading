#pragma once
#include "../ITest.h"

class FloatAddition : public ITest
{
public:
	void Execute(const float*, const float*, float*, size_t) override;
};

