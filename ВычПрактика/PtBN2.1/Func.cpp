#include "Func.h"

int* Create()
{
	int* arr = new int[10001];
	return arr;
}

void Read(int arr[], int& max)
{
	int N;
	fstream file;

	file.open("Input.txt");

	while (!file.eof())
	{
		file >> N;
		if (N > max)
			max = N;

		if (arr[N] == 1)
			arr[N] = 2;
		else
			arr[N] = 1;
	}

	file.close();

}

void CheckAndOut(int arr[], int max)
{
	for (int i = 0; i <= max; i++)
		if (arr[i] == 1)
			cout << i << " ";

	delete[]arr;
}