#include "MatrixMult.h"

int main()
{
	Dim dimA, dimB,dimC;
	getDim("A", &dimA);
	getDim("B", &dimB);
	if (!VerifyDim(dimA, dimB, &dimC))
	{
		cout << "The inner matrix dimensions of A and B are not equal for matrix multiplication" << endl;
		return 0;
	}

	double** A = new double* [dimA.Rows];
	double** B = new double* [dimB.Rows];
	double** C = new double* [dimC.Rows];
	double** CRef = new double* [dimC.Rows];

	for (int i = 0; i < dimA.Rows; i++)
	{
		A[i] = new double[dimA.Cols];
	}
	for (int i = 0; i < dimB.Rows; i++)
	{
		B[i] = new double[dimB.Cols];
	}
	for (int i = 0; i < dimC.Rows; i++)
	{
		C[i] = new double[dimC.Cols];
		CRef[i] = new double[dimC.Cols];
	}

	//Initialize Matrices with Random data
	InitializeArray(A, dimA);
	InitializeArray(B, dimB);

	//Sequential Operation
	chrono::time_point<std::chrono::system_clock> start, end;
	double AverageTime{ 0.0f }; //Average Computation Time

	for (int i = 0; i < NUM_IT; i++)
	{
		start = std::chrono::system_clock::now();
		MatrixMultSeq(A, B, C,dimA, dimB);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elasped_seconds = end - start;
		AverageTime += elasped_seconds.count();
	}
	AverageTime /= NUM_IT;
	AverageTime *= 1000.0f; //Converting seconds to milliseconds

	//Display Average Computation Time and the results
	cout << "Matrix Multiplication: Sequential Execution: Average Computation Time: " << AverageTime << " msecs" << endl;
	DisplayArray("Sequential: Matrix Multiplication", C, dimC);
	//Copying results to reference array
	CopyArray(CRef, C, dimC);

	//Parallel Execution - Matrix Multiplication
	AverageTime = 0.0f; //Average Computation Time
	for (int i = 0; i < NUM_IT; i++)
	{
		start = std::chrono::system_clock::now();
		MatrixMultParallel(A, B, C, dimA, dimB);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elasped_seconds = end - start;
		AverageTime += elasped_seconds.count();
	}
	AverageTime /= NUM_IT;
	AverageTime *= 1000.0f; //Converting seconds to milliseconds

	//Display Average Computation Time and the results
	cout << "Matrix Multiplication: Parallel Execution: Average Computation Time: " << AverageTime << " msecs" << endl;
	DisplayArray("Parallel: Matrix Multiplication", C, dimC);
	Verify(CRef, C, dimC);


	/////////////////Haniye///////////////////
	/////////////////////////////////////////
	//Multiplication with B transposed

	//Create empty matrix for transpose of B
	double** BT = new double* [dimB.Cols];
	for (int i = 0; i < dimB.Cols; i++)
	{
		BT[i] = new double[dimB.Rows];
	}
	//Transpose the B matrix and store in BT
	MatrixTranspose(B, BT, dimB);
	AverageTime = 0.0f; //Average Computation Time

	for (int i = 0; i < NUM_IT; i++)
	{
		start = std::chrono::system_clock::now();
		//Do Multiplication using B-transposed, Sequential computing
		MatrixMultSeqWithTranspose(A, BT, C, dimA, dimB);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elasped_seconds = end - start;
		AverageTime += elasped_seconds.count();
	}
	AverageTime /= NUM_IT;
	AverageTime *= 1000.0f; //Converting seconds to milliseconds

	//Display Average Computation Time and the results
	cout << "Matrix Multiplication with Transposed of Matrix-B: Sequential Execution: Average Computation Time: " << AverageTime << " msecs" << endl;
	DisplayArray("Sequential: Matrix Multiplication", C, dimC);
	//Copying results to reference array
	CopyArray(CRef, C, dimC);


	//Parallel Execution with Transposed of Matrix-B - Matrix Multiplication
	AverageTime = 0.0f; //Average Computation Time
	for (int i = 0; i < NUM_IT; i++)
	{
		start = std::chrono::system_clock::now();
		MatrixMultParallelWithTranspose(A, BT, C, dimA, dimB);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elasped_seconds = end - start;
		AverageTime += elasped_seconds.count();
	}
	AverageTime /= NUM_IT;
	AverageTime *= 1000.0f; //Converting seconds to milliseconds

	//Display Average Computation Time and the results
	cout << "Matrix Multiplication with Transposed of Matrix-B: Parallel Execution: Average Computation Time: " << AverageTime << " msecs" << endl;
	DisplayArray("Parallel: Matrix Multiplication", C, dimC);
	Verify(CRef, C, dimC);



	delete[] A;
	delete[] B;
	delete[] C;
	//Remove allocated memory
	delete[] BT;
	delete[] CRef;
	return 0;
}