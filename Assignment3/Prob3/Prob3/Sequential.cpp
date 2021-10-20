#include "MatrixMult.h"

void MatrixMultSeq(double** arrayA, double** arrayB, double** arrayC, Dim A, Dim B)
{
	for (int i = 0; i < A.Rows; i++)
	{
		for (int j = 0; j < B.Cols; j++)
		{
			float sum = 0.0f;
			for (int k = 0; k < A.Cols; k++)
			{
				sum += arrayA[i][k] * arrayB[k][j];
			}
			arrayC[i][j] = sum;
		}
	}
}

void MatrixMultSeqWithTranspose(double** arrayA, double** arrayBT, double** arrayC, Dim A, Dim BT)
{

	for (int i = 0; i < A.Rows; i++)
	{
		for (int j = 0; j < BT.Cols; j++)
		{
			float sum = 0.0f;
			for (int k = 0; k < A.Cols; k++)
			{
				//For multiplication with transpose of Matrix-B we just need to switch j and k indexes for arrayBT.
				sum += arrayA[i][k] * arrayBT[j][k];
			}
			arrayC[i][j] = sum;
		}
	}
}