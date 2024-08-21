#include <iostream>
#include <thread>


void delay_sleep(const unsigned int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

// Проще было написать
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


int main()
{
	return 0;
}