#include "DataLayout.h"

void InitializeAoS(AoS* aos, int size)
{
	for (int i = 0; i < size; i++)
	{
		aos[i].x = (float)(rand() & 0xFF) / 100.0f;
		aos[i].y = (float)(rand() & 0xFF) / 100.0f;
	}
}

void cpuComputeAoS(AoS* in, AoS* out, int size)
{
	AoS temp;
	chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	for (int i = 0; i < size; i++)
	{
		temp = in[i];
		temp.x += 10.0f;
		temp.y += 20.0f;
		out[i] = temp;
	}
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elasped_seconds = end - start;
	cout << "CPU Sequential Execution time for Array of Structures (AoS) : " << (elasped_seconds.count() * 1000.0f) << " msecs" << endl;
}