#include "Generator.h"

#include <iostream>
#include "Helpers.h"


Generator::Generator()
{
	std::random_device rd;
	random_generator = std::mt19937(rd());

	delay_distribution = std::uniform_int_distribution<>(PERIOD_MIN, PERIOD_MAX);
	latitude_distribution = std::uniform_real_distribution<>(-90, 90);
	longitude_distribution = std::uniform_real_distribution<>(-180, 180);
}

Generator::~Generator()
{
}


void Generator::work(std::atomic_bool& stop_flag)
{
	while (!stop_flag)
	{
		int pause_duration = delay_distribution(random_generator);
		auto point1 = generate();
		auto point2 = generate();
		std::cout << "Generator: " << point1.latitude << ' ' << point1.longitude << ' ' << '\n';
		std::cout << "Generator: " << point2.latitude << ' ' << point2.longitude << ' ' << '\n';
		std::cout << "Generator: " << pause_duration << '\n';
		delay(pause_duration);
	}
}

Geopoint Generator::generate()
{
	return { latitude_distribution(random_generator), longitude_distribution(random_generator) };
}