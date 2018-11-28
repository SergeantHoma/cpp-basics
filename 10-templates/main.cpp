#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

template <class T>
int ReadFile(T** matrix, int size, string file_name);

template <class T>
void PrintMatrix(T** matrix, int size);

template <class T>
void FindK(T** matrix, int size, bool* k);

template <class T>
void SumRowsWithNegatives(T** matrix, int size);

template <class T>
int Execute(string file_name)
{
	int size = 8;
	T** matrix = new T*[size];
	for (int i = 0; i < size; i++)
		matrix[i] = new T[size];

	if (ReadFile(matrix, size, file_name))
		return 1;

	cout << "\nMatrix:\n";
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

int main()
{
	string select;
reselect:
	cout << "Enter type (1 - int, 2 - double, 3 - float) -> ";
	cin >> select;
	if (select < "1" || select > "3")
	{
		cout << "Use only 1, 2 or 3!\n\n";
		goto reselect;
	}

	if (select == "1")
		Execute<int>("int.txt");
	else if (select == "2")
		Execute<double>("double.txt");
	else if (select == "3")
		Execute<float>("float.txt");

	return 0;
}

template <class T>
int ReadFile(T** matrix, int size, string file_name)
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

template <class T>
void PrintMatrix(T** matrix, int size)
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

template <class T>
void FindK(T** matrix, int size, bool* k)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (!(matrix[i][j] == matrix[j][i]))
			{
				k[i] = false;
				break;
			}
}

template <class T>
void SumRowsWithNegatives(T** matrix, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (matrix[i][j] < 0)
			{
				T sum = 0;
				for (int k = 0; k < size; k++)
					sum += matrix[i][k];
				cout << "#" << i + 1 << " row sum: " << sum << endl;
				break;
			}
}