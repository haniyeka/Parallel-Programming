#pragma once

#include <iostream>
#include <iomanip>
#include <chrono>
#include <omp.h>
#include <string>
using namespace std;

//Range for generating random values
constexpr double RANGE_MIN = -1.0f;
constexpr double RANGE_MAX = 1.0f;

//Iteration Count
constexpr int NUM_IT = 10;

void InitializeArray(double** array, int nRows, int nCols);
void InitializeVector(double* vector, int Cols);

void DisplayArray(string text, double** array, int nRows, int nCols);
void DisplayCMean(string text, double* array, int nCols);

bool Verify(double* arrayRef, double* array, int nCols);

//Function to compute the mean sequentially
void ColMeanSeq(double** array, double* vector, int Rows, int Cols);
//Function to compute the mean in parallel
void ColMeanPar(double** array, double* vector, int Rows, int Cols);

void ColMeanSeqOPT(double** array, double* vector, int Rows, int Cols);
void ColMeanParOPT(double** array, double* vector, int Rows, int Cols);
void MatrixTranspose(double** arrayA, double** arrayAT, int Rows, int Cols);

