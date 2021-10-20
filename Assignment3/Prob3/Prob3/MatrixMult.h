#pragma once
#include <iostream>
#include <iomanip>
#include <chrono>
#include <omp.h>
#include <string>
using namespace std;

struct Dim
{
	unsigned int Rows{};
	unsigned int Cols{};
};
typedef struct Dim Dim;

//Range for generating random values
constexpr double RANGE_MIN = -0.5f;
constexpr double RANGE_MAX = 0.5f;

//Iteration Count
constexpr int NUM_IT = 2;

//Function to get the dimensions of a matrix
void getDim(string name,Dim* dim);
//Function to verify the suitability of matrix dimensions for multiplication
bool VerifyDim(Dim dimA, Dim dimB, Dim* dimC);

void InitializeArray(double** array, Dim dim);
void DisplayArray(string text, double** array, Dim dim);
void CopyArray(double** arrayData, double** array, Dim dim);
void Verify(double** arrayData, double** array, Dim dim);

//Fuction for transpose of Matrix-B
void MatrixTranspose(double** arrayB, double** arrayBT, Dim B);

//Matrix Multiplication
void MatrixMultSeq(double** arrayA, double** arrayB, double** arrayC, Dim A,Dim B);
void MatrixMultParallel(double** arrayA, double** arrayB, double** arrayC, Dim A, Dim B);
void MatrixMultSeqWithTranspose(double** arrayA, double** arrayBT, double** arrayC, Dim A, Dim BT);
void MatrixMultParallelWithTranspose(double** arrayA, double** arrayBT, double** arrayC, Dim A, Dim BT);