#include "Random.h"

int Random::GetRandomInt(int min, int max)
{
    std::uniform_int_distribution<int> customDistribution(min, max);
    return customDistribution(generator);
}
