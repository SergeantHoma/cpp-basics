#include <iostream>


using namespace std;

void swap(int * a, int * b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	
	const int kArraySize = 10;
	int arr[kArraySize] = { 0, 2, 3, 4, 5, 0 , 7, 8, 9, 1 };
	int pattern = 0;
	int first_zero = 0;
	int second_zero = 0;
	int multiplication = 1;
	int number_of_zeros = 0; // »звин€юсь за обилие переменных по другому € не смог заставить еЄ работать


	cout << "array numbers is:" << endl;
	for (int i = 0; i < kArraySize; i++)
		cout << arr[i] << endl;
	

	int arr_max = arr[0];
	for (int i = 1; i < kArraySize; i++)
		if (arr[i] > arr_max)
			arr_max = arr[i];
	cout << "Max array number is: " << arr_max << endl;
	

	for (int i = 0; i < kArraySize; i++) 
		if (arr[i] == pattern)
		{
			number_of_zeros++;
		}
	
	if (number_of_zeros>1) //провер€ем наличие двух нулевых элементов
	{
		for (int i = 0; i < kArraySize; i++) //определ€ем первый нулевой элемент
			if (arr[i] == pattern)
			{
				first_zero = i;
				break;
			}
				for (int i = (first_zero + 1); i < kArraySize; i++) //определ€ем второй нулевой элемент
			if (arr[i] == pattern)
			{
				second_zero = i;
				break;
			}
		
		for (int i = (first_zero+1); i < (second_zero); i++) // узнаем произведение
		{
			multiplication *= arr[i];
		}
		cout << "multiplication of array is: ";
		cout << multiplication << endl;
	}
	else 
	{
		cout << "One or more zero elements of the array are missing " << endl;
	}
	
	for (int i = 0; i < kArraySize / 2; ++i)
		for (j = i; j < kArraySize - i; j += 2)
			swap(&arr[j], &arr[j + 1]);

	cout << "array numbers is:" << endl;
	for (int i = 0; i < kArraySize; i++)
	{
		cout << arr[i] << endl;

	}
	return 0;

}