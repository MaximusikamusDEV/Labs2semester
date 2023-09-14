#include "Func.h"


void Enter(int arr[], int& size)
{
	int tmp;
	ifstream file;
	file.open("Input.txt");


	file >> size;

	for (int i = 0; i < size*size; i++)
	{
		file >> tmp;
		arr[i] = tmp;
	}
	file.close();
}

void Fill(int size, int** darr)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			darr[i][j] = 0;

}

void Outer(int size, int** darr)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << darr[i][j] << " \t";
		cout << endl;
	}
}

int** Create(int size)
{
	int** arr = new int* [size];
	for (int i = 0; i < size; i++)
		arr[i] = new int[size];
	return arr;
}



void Put(int size, int** darr, int arr[])
{
	int num = 0;
	int lfl = 0;
	int rgl = 0;
	int upl = 0;
	int dnl = 0;
	bool fl = false;

	while (true)
	{

		for (int i = size - 1 - lfl; i >= lfl; i--)
		{                                                       //filling left line from down to up
			//darr[i][lfl] = arr[num];
			*(*(darr + i) + lfl) = *(arr + num);
			num++;

			if (num == (size * size))
			{
				fl = true;
				break;
			}
		}

		if (fl == true)
			break;

		for (int j = upl + 1; j < size - upl; j++)                  //filling up line from left to right
		{
			//darr[upl][j] = arr[num]; 
			*(*(darr + upl) + j) = *(arr + num);
			num++;


			if (num == (size * size))
			{
				fl = true;
				break;
			}
		}

		if (fl == true)
			break;

		for (int i = rgl + 1; i < size - 1 - rgl; i++)            //filling right line from up to down
		{
			//darr[i][size - 1 - rgl] = arr[num]; 
			*(*(darr + i) + size - 1 - rgl) = *(arr + num);
			num++;


			if (num == (size * size))
			{
				fl = true;
				break;
			}
		}

		if (fl == true)
			break;

		for (int j = size - 1 - dnl; j > dnl; j--)                 //filling down line from right to left
		{
			//darr[size - 1 - dnl][j] = arr[num];  
			*(*(darr + size - 1 - dnl) + j) = *(arr + num);
			num++; 

			if (num == (size * size))
			{
				fl = true;
				break;
			}
		}

		if (fl == true)
			break;
		
		dnl++;
		rgl++;
		upl++;
		lfl++;
	}



	
}