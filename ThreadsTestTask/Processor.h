#pragma once
#include <random>

class Processor
{
public:
	Processor();
	~Processor();

	void process(std::atomic_bool& stop_flag);

private:
	const unsigned int PERIOD_MIN = 100;
	const unsigned int PERIOD_MAX = 600;

	std::mt19937 random_generator;
	std::uniform_int_distribution<> distribution;
};
