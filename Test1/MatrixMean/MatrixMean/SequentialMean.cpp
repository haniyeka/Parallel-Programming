#include "MatrixMean.h"

void ColMeanSeq(double** array, double* vector, int Rows, int Cols)
{
	for (int j = 0; j < Cols; j++)
	{
		double fSum = 0.0f;
		for (int i = 0; i < Rows; i++)
		{
			fSum += array[i][j];
		}
		vector[j] = fSum/Rows;
	}
}

//Write code to implement optimized sequential version to compute Matrix Mean

void ColMeanSeqOPT(double** array, double* vector, int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		double fSum = 0.0f;
		for (int j = 0; j < Cols; j++)
		{
			fSum += array[i][j];
		}
		vector[i] = fSum / Cols;
	}
}