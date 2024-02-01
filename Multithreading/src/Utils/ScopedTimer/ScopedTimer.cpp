#include "ScopedTimer.h"
#include <iostream>

ScopedTimer::ScopedTimer(const std::string& messagePrefix)
	: m_MessagePrefix(messagePrefix), m_Start(std::chrono::high_resolution_clock::now())
{ }

ScopedTimer::~ScopedTimer()
{
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::milliseconds delta = std::chrono::duration_cast<std::chrono::milliseconds>(end - m_Start);
	std::cout << m_MessagePrefix << delta.count() << " ms" << std::endl;
}
