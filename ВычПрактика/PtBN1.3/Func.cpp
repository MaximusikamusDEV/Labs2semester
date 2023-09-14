#include "Func.h"

#include "Func.h"

int* Create(int& size, int& k)
{
	fstream file;

	file.open("Input.txt");

	file >> size;

	file >> k;

	//int arr[1000];

	int* arr = new int[size];

	for (int i = 0; i < size; i++)
		file >> arr[i];

	file.close();


	return arr;
}

int& Find(int& size, int arr[], int& k, int& koord)
{
	int maxi = 0;
	int tmpmaxi;
	int excmaxi = 0;
	int coord;
	int excoord = 0;
	int num = 0;


	for (int i = 0; i < size; i++)
	{
		tmpmaxi = 0;
		num = 0;

		for (int j = 0; j < size; j++)
		{
			if (arr[j] == arr[i] && arr[j] > maxi)
			{
				tmpmaxi = arr[j];
				num++;
			}

			if (arr[i] > excmaxi)
			{
				excmaxi = arr[i];
					excoord = i;
			}
			if (tmpmaxi > maxi && num > 2)
			{
				maxi = tmpmaxi;
				coord = i;
				break;
			}

		}

	}
	
	if (maxi != 0)
	{
		cout << "Element in func: " << maxi << endl;
		koord = coord;
		return maxi;
	}
	else
	{
		cout << "Element in func: " << excmaxi << endl;
		koord = excoord;
		return excmaxi;
	}


}

void ChangeAndOut(int arr[], int size, int koord, int k)
{

	cout << "First array: " << endl;

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

	cout << endl << endl;

	arr[koord] = k;

	cout << "Second array: " << endl;
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";


}