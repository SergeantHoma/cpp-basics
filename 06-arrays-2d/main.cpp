#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int ReadFile(int** matrix, int size, string file_name);
void PrintMatrix(int** matrix, int size);
void FindK(int** matrix, int size, bool* k);
void SumRowsWithNegatives(int** matrix, int size);

int main()
{
	int size = 8;
	int** matrix = new int*[size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];

	if (ReadFile(matrix, size, "file.txt"))
		return 1;

	cout << "Matrix:\n";
	PrintMatrix(matrix, size);
	cout << endl;

	bool* k = new bool[size];
	for (int i = 0; i < size; i++)
		k[i] = true;

	FindK(matrix, size, k);
	for (int i = 0; i < size; i++)
		if (k[i])
			cout << "\nk = " << i + 1;
	cout << endl;

	cout << endl;
	SumRowsWithNegatives(matrix, size);

	for (int i = 0; i < size; i++) delete[] matrix[i];
	delete[] matrix;

	return 0;
}

int ReadFile(int** matrix, int size, string file_name)
{
	ifstream fin(file_name);
	if (!fin.is_open())
	{
		cout << "can't open file: " << file_name << endl;
		return 1;
	}

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			fin >> matrix[i][j];

	fin.close();
	return 0;
}

void PrintMatrix(int** matrix, int size)
{
	cout << string(5 * size + 1, '-') << endl;
	for (int i = 0; i < size; i++) {
		cout << "|";
		for (int j = 0; j < size; j++)
			cout << setw(3) << matrix[i][j] << setw(2) << "|";
		cout << endl;
	}
	cout << string(5 * size + 1, '-');
}

void FindK(int** matrix, int size, bool* k)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (!(matrix[i][j] == matrix[j][i]))
			{
				k[i] = false;
				break;
			}
}

void SumRowsWithNegatives(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (matrix[i][j] < 0)
			{
				int sum = 0;
				for (int k = 0; k < size; k++)
					sum += matrix[i][k];
				cout << "#" << i + 1 << " row sum: " << sum << endl;
				break;
			}
}