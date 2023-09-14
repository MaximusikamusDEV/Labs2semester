#include "Func.h"

void Read(Matrix& arr, int& maxi)
{
	int size;
	int num;

	fstream file;
	file.open("Input1.txt");
		
	file >> size;
		arr.addcol(size);
		arr.addrow(size);

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				file >> num;
				
				maxi = max(maxi, num);
				arr[i][j] = num;
			}
	    }

		cout << endl;

	file.close();
}


void Ans(Matrix arr, Vector& endvect, int maxi)
{
	int size = arr.m_col;
	int tmp = 0;

	for (int i = 0; i < size * size; i++)
		endvect.PushBack(maxi);

	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size - j; i++)
		{
			if (arr[i][size - j - i - 1] < endvect[tmp])
				endvect[tmp] = arr[i][size - j - i - 1];
		}

		tmp++;
	}


	for (int j = 0; j < size; j++)
	{
		for (int i = j + 1; i < size; i++)
		{
			if (arr[i][size - i + j] < endvect[tmp])
				endvect[tmp] = arr[i][size - i + j];
		}

		tmp++;
	}


	for (int i = 0; i < size * 2 - 1; i++)
		cout << endvect[i] << " ";

	cout << endl;
}