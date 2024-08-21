#include "Generator.h"

#include <iostream>
#include "Helpers.h"


Generator::Generator()
{
	std::random_device rd;
	random_generator = std::mt19937(rd());
	distribution = std::uniform_int_distribution<>(PERIOD_MIN, PERIOD_MAX);
}

Generator::~Generator()
{
}


void Generator::work(std::atomic_bool& stop_flag)
{
	while (!stop_flag)
	{
		int pause_duration = distribution(random_generator);
		// auto point = generate;
		std::cout << "Generator: " << pause_duration << '\n';
		delay(pause_duration);
	}
}

//Geopoint Generator::generate()
//{
//}