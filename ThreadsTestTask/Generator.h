#pragma once
#include <random>

class Generator
{
public:
	Generator();
	~Generator();

	void work(std::atomic_bool& stop_flag);
	//Geopoint generate();

private:
	const unsigned int PERIOD_MIN = 200;
	const unsigned int PERIOD_MAX = 500;

	std::mt19937 random_generator;
	std::uniform_int_distribution<> distribution;
};
