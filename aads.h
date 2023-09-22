#ifndef ALGORITHMS_AND_DATA_STRUCTURES
#define ALGORITHMS_AND_DATA_STRUCTURES
#include "stdlib.h"


// Assignment 1;
size_t fibonacci(size_t n);
size_t fibonacci_recursive(size_t n);

size_t countArrayUniques_taskA(int *array,size_t arraySize);
size_t countArrayUniques_taskB(int *array, size_t arraySize, int k);

size_t factorial(unsigned int n);

size_t findLostNumber(int *array, int n);

bool isInArray(int dim,int (*array)[dim],int a);

bool checkSudoku (size_t dim, int (array[])[dim]);

// ---------- //

// Seminar 2
bool bracketSequence();
bool complexBracketSequence();

// ---------- //

#endif