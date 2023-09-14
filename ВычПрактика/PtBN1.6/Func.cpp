#include "Func.h"

int* Create(int size)
{
	int* arr = new int[size+2];
	return arr;
}

void ReadSize(int& size)
{
	ifstream file;
	file.open("Input.txt");

	file >> size;

	file.close();

}

void ReadArr(int arr[])
{
	ifstream file;
	file.open("Input.txt");

	int size;

	file >> size;

	for (int i = 0; i < size; i++)
		file >> arr[i];

	file.close();
}

void Merge(int* arr, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		Merge(arr, low, mid);
		Merge(arr, mid + 1, high);
		Sort(arr, low, high, mid);
	}
}


void Sort(int* arr, int low, int high, int mid)
{
	int* sarr;
	sarr = Create(high);
	int i = low;
	int j = mid + 1;
	int k = low;


	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
		{
			sarr[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			sarr[k] = arr[j];
			k++;
			j++;
		}
	}

	while(i <= mid)
	{
		sarr[k] = arr[i];
		k++;
		i++;
	}

	while (j <= high)
	{
		sarr[k] = arr[j];
		j++;
		k++;
	}

	for (i = low; i < k; i++)
	{
		arr[i] = sarr[i];
	}

	delete[](sarr);

}

void Output(int arr[], int size)
{

	for (int i = 0; i < size; i++)
	 cout << arr[i] << " ";

	cout << endl;

	//delete[](arr);

}