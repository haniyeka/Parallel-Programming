#pragma once
#include <iostream>
#include <chrono>
#include <omp.h>

using namespace std;

//Range for generating random values
constexpr double RANGE_MIN = -2.5f;
constexpr double RANGE_MAX = 2.5f;

//Iteration Count
constexpr int NUM_IT = 10;



//Function to initialize the array with random values
void InitializeArray(double* array, int nSize);

//Function to compute the sum of the elements of the array sequentially
double ArraySumSequential(double* AverageTime, double* array, int Size);


//Function to compute the sum of the elements of the array in parallel
//Parallelization is implemented with Manual Partitioning
double ArraySumParallel_ManualPartition(double* AverageTime, double* array, int Size,int ThreadCount);

//Parallelization is implemented with Manual Partitioning
double ArraySumParallel_Reduction(double* AverageTime, double* array, int Size, int ThreadCount);






