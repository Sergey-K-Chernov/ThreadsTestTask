#include "Processor.h"

#include <iostream>
#include "Helpers.h"
#include "Synchronization.h"
#include "PointsQueue.h"

Processor::Processor(PointsQueue& queue, SynchronizationData& synchro) : queue(queue), synchro(synchro)
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
		std::unique_lock<std::mutex> synchro_lock(synchro.mutex);
		while (!synchro.got_next)
		{
			synchro.cv.wait(synchro_lock);
		}
		synchro.got_next = false;

		// ����, ��� ��� ���� ���������� ��� ����������� ��������.
		// ����� ���� �� ������ synchro.got_next ������������ �������, �� �������, ��� ��� ��������.
		while (auto result = queue.get())
		{
			auto pair = result.value();
			queue.pop();

			int processing_duration = distribution(random_generator);
			delay(processing_duration);

			std::cout //<< "Processor:\n"
				<< "{{" << pair.first.latitude << ", " << pair.first.longitude << "}, "
				<< "{" << pair.second.latitude << ", " << pair.second.longitude << "}, "
				<< processing_duration << "}\n";
		}
	}
}