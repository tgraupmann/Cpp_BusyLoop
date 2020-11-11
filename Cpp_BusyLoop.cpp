// Cpp_BusyLoop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>


using namespace std;


void KeepThreadBusy()
{
	volatile unsigned x = 0, y = 1;
	while ((x++ || y++));
}

int main()
{
    std::cout << "Starting threads to starve other processes!\n";

	constexpr int numBusyThreads = 12;
	thread threads[numBusyThreads];
	for (int i = 0; i < numBusyThreads; ++i)
	{
		threads[i] = thread(KeepThreadBusy);
	}

	for (int i = 0; i < numBusyThreads; ++i)
	{
		threads[i].join();
	}

    return 0;
}
