#include <iostream>
#include <thread>
#include <random>



void delay_sleep(const unsigned int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}


// Проще было написать, чем уточнять, какой вариант ожидания требуется в задании
void delay_busy_loop(const unsigned int milliseconds)
{
	auto start = std::chrono::high_resolution_clock::now();
	while (milliseconds > std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count())
	{ // wait
	}
}


void delay(const unsigned int milliseconds)
{
	delay_sleep(milliseconds);
	//wait_busy_loop(milliseconds);
}


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

Generator::Generator()
{
	std::random_device rd;
	random_generator = std::mt19937(rd());
	distribution = std::uniform_int_distribution<>(GENERATION_PERIOD_MIN, GENERATION_PERIOD_MAX);
}

Generator::~Generator()
{
}


void Generator::work()
{
	while (true)
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


int main()
{
	Generator generator;

	generator.work();
	return 0;
}