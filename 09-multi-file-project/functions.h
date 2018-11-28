#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Zeroes
{
	int first_zero_index = -1;
	int second_zero_index = -1;
};

Zeroes FindZeroes(int a[], int const size);
int ProductBetweenZeroes(int a[], const int size, Zeroes z);
void PrintArray(int array[], int const size);
void SortArray(int a[], int const size);
int IndexMaxElment(int a[], int size);