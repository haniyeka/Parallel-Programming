#include "MatrixMean.h"

void InitializeArray(double** array, int nRows, int nCols)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			array[i][j] = ((double)rand() / ((double)RAND_MAX + 1.0f) * (RANGE_MAX - RANGE_MIN) + RANGE_MIN);
		}
	}
}

void InitializeVector(double* vector, int Cols)
{
	for (int i = 0; i < Cols; i++)
	{
		vector[i] = 0.0f;
	}
}

void DisplayArray(string text, double** array, int nRows, int nCols)
{
	if (nRows <= 6 && nCols <= 6)
	{
		cout << text << endl;
		for (int i = 0; i < nRows; i++)
		{
			for (int j = 0; j < nCols; j++)
			{
				cout << setprecision(4) << array[i][j] << '\t';
			}
			cout << endl;
		}
	}
}

void DisplayCMean(string text, double* array, int nCols)
{
	if(nCols <= 6)
	{
		cout << text << endl;
		for (int j = 0; j < nCols; j++)
		{
			cout << setprecision(4) << array[j] << '\t';
		}
		cout << endl;
	}
}

bool Verify(double* arrayRef, double* array, int nCols)
{
	double tol = 1.0E-08;
	for (int j = 0; j < nCols; j++)
	{
		if (fabs(arrayRef[j] - array[j]) > tol)
		{
			cout << "Error: j = " << j << " " << arrayRef[j] << "\t" << array[j] << endl;
			return false;
		}
	}
	return true;
}


//Add additional functions for Memory Optimization
//fuction for transposing matrix 
void MatrixTranspose(double** arrayA, double** arrayAT, int Rows, int Cols) {
	for (int i = 0; i < Rows; ++i) {
		for (int j = 0; j < Cols; ++j) {
			arrayAT[j][i] = arrayA[i][j];
		}
	}
}