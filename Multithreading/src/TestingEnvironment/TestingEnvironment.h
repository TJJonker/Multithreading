#pragma once
#include <functional>

typedef std::function<void(const float* a, const float* b, float* r, const size_t size)> TestFunction;

class TestingEnvironment
{
public:
	void RunTest();
	void SetTest(TestFunction function) { m_TestFunction = function; }
	void SetResultCheck(TestFunction function) { m_CheckFunction = function; }

private:
	TestFunction m_TestFunction;
	TestFunction m_CheckFunction;
};

