#include "Processor.h"

#include <iostream>
#include "Helpers.h"
#include "PointsQueue.h"

Processor::Processor(PointsQueue& queue) : queue(queue)
{
	std::random_device rd;
	random_generator = std::mt19937(rd());
	distribution = std::uniform_int_distribution<>(PERIOD_MIN, PERIOD_MAX);
}

Processor::~Processor()
{
}


void Processor::process(std::atomic_bool& stop_flag)
{
	while (!stop_flag)
	{
		int processing_duration = distribution(random_generator);

		auto result = queue.get(); // Тут переделать с optional на явное уведомление о новой точке
		if (!result)
			continue;

		auto pair = result.value();
		queue.pop();
		delay(processing_duration);
		// Тут еще добавить мьютекс на вывод? Или через sstream?..
		std::cout << "Processor:\n"
			<< "P1 = {" << pair.first.latitude  << ", " << pair.first.longitude << "}\n"
			<< "P2 = {" << pair.second.latitude << ", " << pair.second.longitude << "}\n"
			<< processing_duration << '\n';

	}
}