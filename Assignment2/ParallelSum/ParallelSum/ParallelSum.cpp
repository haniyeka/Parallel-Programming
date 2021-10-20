#include "Sum.h"

//Parallelization with Manual Partitioning
double ArraySumParallel_ManualPartition(double* AverageTime, double* array, int Size, int ThreadCount)
{	
	chrono::time_point<std::chrono::system_clock> start, end;
	*AverageTime = 0.0f;
	double sum;
	int ArrayDivision; //Variable to store the number of elements per thread of the array
	//Compute the number of elements per thread
	//Ensures divisions is a multiple of number of Threads
	Size = (Size / ThreadCount) * ThreadCount;
	//Divide manually the total number of divisions among the number of threads
	ArrayDivision = Size / ThreadCount;

	//Define an additional array to implement manual partitioning
	double* PartitionSum = new double[ThreadCount];

	for (int iter = 0; iter < NUM_IT; iter++)
	{
		//Start Timer
		start = std::chrono::system_clock::now();
		//Implement OMP based Parallelization with manual partitioning using only Parallel region and desired number of threads
#pragma omp parallel num_threads(ThreadCount)
		{
			//Obtain the current thread Id
			_int64 threadId = omp_get_thread_num();
			//Determine the start index of each thread division section
			int threadStartIndex = threadId * ArrayDivision;
			//Determine the end index of each thread division section
			int threadEndIndex = threadStartIndex + ArrayDivision;
			//Compute sum for each partition
			PartitionSum[threadId] = 0;
			for (int i = threadStartIndex; i < threadEndIndex; i++)
			{
				PartitionSum[threadId] += array[i];
			}		
		}	
		//Computing the final sum
		sum = PartitionSum[0];
		for (int k = 1; k < ThreadCount; k++)
		{
			sum += PartitionSum[k];
		}

		//Stop timer
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elasped_seconds = end - start;
		*AverageTime += elasped_seconds.count();
	}
	*AverageTime /= NUM_IT;
	*AverageTime *= 1000.0f; //Converting seconds to milliseconds
	//Release dynamically allocated Memory
	delete[] PartitionSum;
	return sum; //Return the sum of the last iteration
}


//Parallelization with Reduction
double ArraySumParallel_Reduction(double* AverageTime, double* array, int Size, int ThreadCount)
{
	chrono::time_point<std::chrono::system_clock> start, end;
	*AverageTime = 0.0f;
	double sum;
	int ArrayDivision; //Variable to store the number of elements per thread of the array
	//Compute the number of elements per thread
	Size = (Size / ThreadCount) * ThreadCount;
	//Divide manually the total number of divisions among the number of threads
	ArrayDivision = Size / ThreadCount;


	for (int iter = 0; iter < NUM_IT; iter++)
	{
		sum = 0.0f;
		//Start Timer
		start = std::chrono::system_clock::now();
		//Implement OMP based Parallelization with Reduction and Parallel region and desired number of threads
#pragma omp parallel num_threads(ThreadCount), reduction(+:sum)
		{
			//Obtain the current thread Id
			_int64 threadId = omp_get_thread_num();
			//Determine the start index of each thread division section
			int threadStartIndex = threadId * ArrayDivision;
			//Determine the end index of each thread division section
			int threadEndIndex = threadStartIndex + ArrayDivision;
			//Compute sum for each partition
			for (int i = threadStartIndex; i < threadEndIndex; i++)
			{
				sum += array[i];
			}
		}

		//Stop timer
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elasped_seconds = end - start;
		*AverageTime += elasped_seconds.count();
	}
	*AverageTime /= NUM_IT;
	*AverageTime *= 1000.0f; //Converting seconds to milliseconds
	return sum; //Return the sum of the last iteration
}