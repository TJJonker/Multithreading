#include <iostream>
#include "ScopedTimer.h"

int main() {
	{
		ScopedTimer timer("Time: ");
		for (int i = 0; i < 10000; i++) {
			std::cout << 3 * i * i << std::endl;
		}
	}
}