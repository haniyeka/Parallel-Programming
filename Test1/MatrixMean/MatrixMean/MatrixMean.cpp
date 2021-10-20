#include "MatrixMean.h"

int main()
{
	int nRows{}, nCols{};
	cout << "Enter number of rows: ";
	cin >> nRows;
	cout << "Enter number of cols: ";
	cin >> nCols;

	double** A = new double* [nRows];
	for (int i = 0; i < nRows; i++)
	{
		A[i] = new double[nCols];
	}

	//Initialize Arrays
	InitializeArray(A, nRows, nCols);

	//Vector to store the column mean computed sequentially
	double* CMeanSeq = new double[nCols];

	chrono::time_point<std::chrono::system_clock> start, end;
	double AverageTime{ 0.0f }; //Average Computation Time

	//Sequential Execution
	for (int i = 0; i < NUM_IT; i++)
	{
		InitializeVector(CMeanSeq, nCols);
		start = std::chrono::system_clock::now();
		ColMeanSeq(A, CMeanSeq, nRows, nCols);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elasped_seconds = end - start;
		AverageTime += elasped_seconds.count();
	}
	AverageTime /= NUM_IT;
	AverageTime *= 1000.0f; //Converting seconds to milliseconds

	//Display Average Computation Time and the results
	cout << "Matrix Mean: Sequential Execution Unoptimized: Average Computation Time: " << AverageTime << " msecs" << endl;
	DisplayArray("Matrix", A, nRows, nCols);
	DisplayCMean("Column Mean - Sequential Unoptimized", CMeanSeq, nCols);

	//Parallel Execution
	AverageTime = 0.0f;

	////Vector to store the column mean computed in parallel
	double* CMeanPar = new double[nCols];

	//Implement code to compute the column mean in parallel.
	for (int i = 0; i < NUM_IT; i++)
	{
		InitializeVector(CMeanPar, nCols);
		start = std::chrono::system_clock::now();
		ColMeanPar(A, CMeanPar, nRows, nCols);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elasped_seconds = end - start;
		AverageTime += elasped_seconds.count();
	}
	
	AverageTime /= NUM_IT;
	AverageTime *= 1000.0f; //Converting seconds to milliseconds

	//Display Average Computation Time and the results
	cout << "Matrix Mean: Parallel Execution Unoptimized: Average Computation Time: " << AverageTime << " msecs" << endl;
	DisplayCMean("Column Mean - Parallel Unoptimized", CMeanPar, nCols);

	//Call Verify Function to verify the results
	if (Verify(CMeanSeq, CMeanPar, nCols))
	{
		cout << "Verification: Success" << endl;
	}


	//Write code to implement optimized versions of sequential and parallel versions of Matrix Mean

	double** AT = new double* [nCols];
	for (int j = 0; j < nCols; j++)
	{
		AT[j] = new double[nRows];
	}
	MatrixTranspose(A, AT, nRows, nCols);
	//Vector to store the column mean computed sequentially
	double* CMeanSeqOPT = new double[nRows];
	AverageTime = 0.0f; //Average Computation Time

	//Sequential Execution
	for (int i = 0; i < NUM_IT; i++)
	{
		InitializeVector(CMeanSeqOPT, nRows);
		start = std::chrono::system_clock::now();
		ColMeanSeqOPT(AT, CMeanSeqOPT, nCols, nRows);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elasped_seconds = end - start;
		AverageTime += elasped_seconds.count();
	}
	AverageTime /= NUM_IT;
	AverageTime *= 1000.0f; //Converting seconds to milliseconds

	//Display Average Computation Time and the results
	cout << "Matrix Mean: Sequential Execution Optimized: Average Computation Time: " << AverageTime << " msecs" << endl;
	DisplayCMean("Column Mean - Sequential Optimized", CMeanSeqOPT, nRows);

	//Parallel Execution
	AverageTime = 0.0f;

	////Vector to store the column mean computed in parallel
	double* CMeanParOPT = new double[nRows];

	//Implement code to compute the column mean in parallel.
	for (int i = 0; i < NUM_IT; i++)
	{
		InitializeVector(CMeanParOPT, nRows);
		start = std::chrono::system_clock::now();
		ColMeanParOPT(AT, CMeanParOPT, nCols, nRows);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elasped_seconds = end - start;
		AverageTime += elasped_seconds.count();
	}

	AverageTime /= NUM_IT;
	AverageTime *= 1000.0f; //Converting seconds to milliseconds

	//Display Average Computation Time and the results
	cout << "Matrix Mean: Parallel Execution Optimized: Average Computation Time: " << AverageTime << " msecs" << endl;
	DisplayCMean("Column Mean - Parallel Optimized", CMeanParOPT, nRows);

	//Call Verify Function to verify the results
	if (Verify(CMeanSeqOPT, CMeanParOPT, nRows))
	{
		cout << "Verification: Success" << endl;
	}






	delete[] A;
	delete[] AT;
	delete[] CMeanSeq;
	delete[] CMeanSeqOPT;
	delete[] CMeanPar;
	delete[] CMeanParOPT;
	return 0;
}