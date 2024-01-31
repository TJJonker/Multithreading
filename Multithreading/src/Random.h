#include <random>

class Random {
public:
    Random() : generator(std::random_device{}()), distribution(0, std::numeric_limits<int>::max()) {}

    int GetRandomInt(int min, int max);

private:
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;
};