#pragma once

struct ITest {
	virtual void Execute(const float*, const float*, float*, size_t) = 0;
};