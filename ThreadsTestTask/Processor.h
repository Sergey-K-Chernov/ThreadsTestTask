#pragma once
#include <random>

class PointsQueue;

class Processor
{
public:
	Processor() = delete;
	Processor(PointsQueue& queue);
	~Processor();

	void process(std::atomic_bool& stop_flag);

private:
	PointsQueue& queue;

	const unsigned int PERIOD_MIN = 100;
	const unsigned int PERIOD_MAX = 600;

	std::mt19937 random_generator;
	std::uniform_int_distribution<> distribution;
};
