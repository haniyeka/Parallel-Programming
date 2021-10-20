#include "MatrixMult.h"

void MatrixMultParallel(double** arrayA, double** arrayB, double** arrayC, Dim A, Dim B)
{
#pragma omp parallel for
	for (int i = 0; i < A.Rows; i++)
	{
#pragma omp parallel for
		for (int j = 0; j < B.Cols; j++)
		{
			float sum = 0.0f;
#pragma omp parallel for reduction(+:sum)
			for (int k = 0; k < A.Cols; k++)
			{
				sum += arrayA[i][k] * arrayB[k][j];
			}
			arrayC[i][j] = sum;
		}
	}
}

void MatrixMultParallelWithTranspose(double** arrayA, double** arrayBT, double** arrayC, Dim A, Dim BT) {
#pragma omp parallel for
	for (int i = 0; i < A.Rows; i++)
	{
#pragma omp parallel for
		for (int j = 0; j < BT.Cols; j++)
		{
			float sum = 0.0f;
#pragma omp parallel for reduction(+:sum)
			for (int k = 0; k < A.Cols; k++)
			{
				//For multiplication with transpose of Matrix-B we just need to switch j and k indexes for arrayBT.
				sum += arrayA[i][k] * arrayBT[j][k];
			}
			arrayC[i][j] = sum;
		}
	}
}