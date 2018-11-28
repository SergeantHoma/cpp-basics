#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Zeroes
{
	int first_zero_index = -1;
	int second_zero_index = -1;
};

Zeroes FindZeroes(int a[], int const size)
{
	Zeroes z;
	for (int i = 0; i < size; i++)
	{
		if (a[i] == 0)
		{
			if (z.first_zero_index == -1)
			{
				z.first_zero_index = i;
				continue;
			}
			else
			{
				z.second_zero_index = i;
				break;
			}
		}
	}
	return z;
}

int ProductBetweenZeroes(int a[], const int size, Zeroes z)
{
	int result = 1;
	for (int i = z.first_zero_index + 1; i < z.second_zero_index; i++)
	{
		result *= a[i];
	}
	return result;

}

void PrintArray(int array[], int const size)
{
	cout << string(61, '-') << "\n|";

	for (int i = 0; i < size; i++)
		cout << setw(2) << "[" << i << "]" << setw(2) << "|";

	cout << " <- index\n";
	cout << string(61, '-') << "\n|";

	for (int i = 0; i < size; i++)
		cout << setw(3) << array[i] << setw(3) << "|";

	cout << " <- array\n";
	cout << string(61, '-');
}

void SortArray(int a[], int const size)
{
	int *b = new int[size];
	int index = 0;
	for (int i = 0; i < size; i += 2)
	{
		b[index] = a[i];
		index++;
	}
	for (int i = 1; i < size; i += 2)
	{
		b[index] = a[i];
		index++;
	}
	for (int i = 0; i < size; i++)
	{
		a[i] = b[i];
	}
}

int IndexMaxElment(int a[], int size)
{
	int max = a[0];
	int index_max = 0;
	for (int i = 1; i < size; i++)
	{
		if (a[i] > max)
		{
			index_max = i;
			max = a[i];
		}
	}
	return index_max;
}

int main() {
	int const kArraySize = 10;
	int array[kArraySize] = { 0, -1, -2, 1, -4, 0, -6, 1, 3, -2 };

	cout << "Starting Array:" << endl;
	PrintArray(array, kArraySize);
	cout << endl;

	cout << "\nIndex of max element in the array: ";
	cout << IndexMaxElment(array, kArraySize) << endl;

	cout << "\nProduct of elements between zeroes: ";
	Zeroes z = FindZeroes(array, kArraySize);
	if (z.first_zero_index != -1 && z.second_zero_index != -1)
	{
		if ((z.second_zero_index - z.first_zero_index) > 1)
			cout << ProductBetweenZeroes(array, kArraySize, z);
		else
			cout << "Error: no elements between zeroes!";
	}
	else
	{
		cout << "Error: less than 2 zeroes in the array!";
	}
	cout << endl;

	cout << "\nSorted Array:\n";
	SortArray(array, kArraySize);
	PrintArray(array, kArraySize);

	return 0;
}