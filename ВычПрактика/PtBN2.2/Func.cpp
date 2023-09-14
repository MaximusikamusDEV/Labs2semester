#include "Func.h"

void Read(int& size)
{
	fstream file;
	file.open("Input2.txt");
	file >> size;
	file.close();
}

int* Create(int size)
{
	int* arr = new int[size*size];
	return arr;
}

int** Create(int size, int k)
{
	int** arr = new int* [size];
	for (int i = 0; i < size; i++)
		arr[i] = new int[size];


	return arr;
}

void Fill(int arr[], int* arr2[], int maxi[])
{
	int tmp;
	int size;
	int maxitmp = 0;
	
	fstream file;
	file.open("Input2.txt");
	file >> size;

	while (!file.eof())
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
		        file >> tmp;
				if (tmp > maxitmp)
                 maxitmp = tmp;

				arr2[i][j] = tmp;
				arr[i * size + j] = tmp;
			}
		}
	}

	for (int i = 0; i < size * size; i++)
		maxi[i] = maxitmp;

	file.close();

}

void Ans(int* arr[], int size, int maxi[])
{
	int num = size;
	int fl = 1;
	int step = 0;
	int tmp = 0;

		for (int j = 0; j < size; j++)
		{
			for (int i = 0; i < size-j; i++)
			{
				if (arr[i][size - j - i - 1] < maxi[tmp])
					maxi[tmp] = arr[i][size - j - i - 1];
					
				step++;

			}

			tmp++;
		}


		for (int j = 0; j < size; j++)
		{
			for (int i = j + 1; i < size; i++)
			{
				if (arr[i][size - i + j] < maxi[tmp])
					maxi[tmp] = arr[i][size - i + j];
				
				step++;
			}
			
			tmp++;

		}

		delete[] arr;

		//cout << step << " Nums" << endl;

}

void ZeroToMax(int maxi[], int maxitmp, int size)
{
	for (int i = 0; i < size*size; i++)
		maxi[i] = maxitmp;
}

void Ans(int arr[], int size, int maxi[])
{
	int num = size;
	int fl = 1;
	int step = 0;
	int tmp = 0;

	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size - j; i++)
		{
			if (arr[i*size + size - j - i - 1] < maxi[tmp])
				maxi[tmp] = arr[i*size + size - j - i - 1];
			
			step++;

		}

		 
		tmp++;
	}


	for (int j = 0; j < size; j++)
	{
		for (int i = j + 1; i < size; i++)
		{
			if (arr[i*size + size - i + j] < maxi[tmp])
			  maxi[tmp] = arr[i* size + size - i + j];
			
			step++;
		}

		tmp++;

	}

	delete[] arr;

	//cout << endl << step << " Nums";

}


void Output(int maxi[], int size)
{
	for (int i = 0; i < size*2-1; i++)
		cout << maxi[i] << " ";
	delete[] maxi;
}