#pragma once

struct ITest {
	virtual void Execute(float*, float*, float*, size_t) = 0;
};