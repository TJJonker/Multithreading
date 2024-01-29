#pragma once
#include <string>
#include <chrono>

class ScopedTimer
{
public:
	ScopedTimer(const std::string& messagePrefix);
	~ScopedTimer();

private:
	std::string m_MessagePrefix;
	std::chrono::high_resolution_clock::time_point m_Start;
};

