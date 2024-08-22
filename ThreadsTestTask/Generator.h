#pragma once
#include <random>

#include "Geopoint.h"

class PointsQueue;
class SynchronizationData;

class Generator
{
public:
	Generator() = delete;
	Generator(PointsQueue& queue, SynchronizationData& synchro);

	~Generator();

	void work(std::atomic_bool& stop_flag);
	Geopoint generate();

private:
	PointsQueue& queue;
	SynchronizationData& synchro;

	const unsigned int PERIOD_MIN = 200;
	const unsigned int PERIOD_MAX = 500;

	std::mt19937 random_generator;
	std::uniform_int_distribution<> delay_distribution;

	std::uniform_real_distribution<> latitude_distribution;
	std::uniform_real_distribution<> longitude_distribution;
};
