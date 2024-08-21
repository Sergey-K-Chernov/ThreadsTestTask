#include "Processor.h"

#include <iostream>
#include "Helpers.h"

Processor::Processor()
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
		// auto point = generate;
		std::cout << "Processor: " << processing_duration << '\n';
		delay(processing_duration);
	}
}