#pragma once
#include <random>

class Generator
{
public:
	Generator();
	~Generator();

	void work();
	//Geopoint generate();

private:
	const unsigned int GENERATION_PERIOD_MIN = 200;
	const unsigned int GENERATION_PERIOD_MAX = 500;

	std::mt19937 random_generator;
	std::uniform_int_distribution<> distribution;
};
