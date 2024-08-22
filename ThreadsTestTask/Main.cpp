#include <iostream>
#include <thread>

#include "Synchronization.h"
#include "Generator.h"
#include "Processor.h"
#include "PointsQueue.h"

int main()
{
	std::atomic_bool stop_flag = false;
	SynchronizationData synchro;
	PointsQueue queue;

	Generator generator(queue, synchro);
	Processor processor(queue, synchro);

	std::cout << "Press 'Enter' to start simulation then press 'Enter' again to stop it.";
	std::cin.get();

	std::thread generator_thread(&Generator::work, generator, std::ref(stop_flag));
	std::thread processor_thread(&Processor::process, processor, std::ref(stop_flag));

	std::cin.get();

	stop_flag.store(true);
	generator_thread.join();
	processor_thread.join();

	return 0;
}