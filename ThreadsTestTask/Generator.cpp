#include "Generator.h"

#include <iostream>
#include "Helpers.h"
#include "Synchronization.h"
#include "PointsQueue.h"


Generator::Generator(PointsQueue& queue, SynchronizationData& synchro) : queue(queue), synchro(synchro)
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
		delay(pause_duration);

		
		queue.push(std::make_pair(generate(), generate()));

		std::unique_lock<std::mutex> synchro_lock(synchro.mutex);
		synchro.got_next = true;
		//std::cout << "Generator: " << pause_duration << '\n';
		synchro.cv.notify_all();
		
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