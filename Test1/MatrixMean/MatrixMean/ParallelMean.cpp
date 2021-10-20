#include "MatrixMean.h"

void ColMeanPar(double** array, double* vector, int Rows, int Cols)
{
	double fSum = 0.0f; // local variable to store the sum of each column
	int max_threads = omp_get_max_threads(); // gives the maximum number of logical threads of the CPU
#pragma omp parallel for
	//Write code to compute the matrix mean in parallel
	for (int j = 0; j < Cols; j++)
	{
		double fSum = 0.0f;
#pragma omp parallel for reduction(+:fSum)
		for (int i = 0; i < Rows; i++)
		{
			fSum += array[i][j];
		}
		vector[j] = fSum / Rows;
	}
}

//Write code to implement optimized parallel version to compute Matrix Mean

void ColMeanParOPT(double** array, double* vector, int Rows, int Cols)
{
	double fSum = 0.0f; // local variable to store the sum of each column
	int max_threads = omp_get_max_threads(); // gives the maximum number of logical threads of the CPU
#pragma omp parallel for
	//Write code to compute the matrix mean in parallel
	for (int i = 0; i < Rows; i++)
	{
		double fSum = 0.0f;
#pragma omp parallel for reduction(+:fSum)
		for (int j = 0; j < Cols; j++)
		{
			fSum += array[i][j];
		}
		vector[i] = fSum / Cols;
	}
}