#include "functions.h"

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