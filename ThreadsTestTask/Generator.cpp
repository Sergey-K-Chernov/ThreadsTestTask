#include "Generator.h"

#include <iostream>
#include "Helpers.h"
#include "PointsQueue.h"


Generator::Generator(PointsQueue& queue) : queue(queue)
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

		queue.push(std::make_pair(generate(), generate()));

		std::cout << "Generator: " << pause_duration << '\n';
		delay(pause_duration);
	}
}

Geopoint Generator::generate()
{
	Geopoint g{
		latitude_distribution(random_generator),
		longitude_distribution(random_generator)
	};
	return g;
}