#include "Funcs.h";

void EnterArr(int &size, int arr[])
{
	cout << "Enter size of array: ";
	cin >> size;

	cout << "Enter your array: ";

	for (int i = 0; i < size; i++)
		cin >> arr[i];

}

void SortArr(int size, int arr[])
{
	for (int i = 1; i < size; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
			swap(arr[j - 1], arr[j]);
}

void findboard(int& board, int size)
{
	for (int i = 1; i < size; i++)
		if ((i % 2 == 1) && ((size - i * 2) % 2) == 1 && (((size - i * 2) / 2 + 2) == (i / 2 + 1)))
		{
			board = i;
				return;
		}
}



void Transfer(int size, int arr[], int board)
{
	int k = 0;
	int darr[50][50];
	int num = size - board * 2 + 2;

	for (int i = board - 1; i >= 0; i--)
	{
		darr[i][0] = arr[k];
		k++;
	}

	for (int i = 0; i < board; i++)
		for (int j = 1; j <= board - 2; j++)
		{
			if (i == j && i < board / 2 + 1)
			{
				darr[i][j] = arr[k];
				k++;
			}
			else
				darr[i][j] = 0;
		}

	for (int i = board - 1; i >= 0; i--)
		for (int j = num / 2 + 1; j < board; j++)
		{
			if ((board - i + 1) == j + 2)
			{
				darr[i][j] = arr[k];
				k++;
			}
			else
				darr[i][j] = 0;
		}

	for (int i = 1; i < board; i++)
	{
		darr[i][board - 1] = arr[k];
		k++;
    }

	for (int i = 0; i < board; i++)
	{
		for (int j = 0; j < num; j++)
			cout << darr[i][j] << " ";

		cout << endl;
	}


}





/*void Check(int& size)
{
	if ((size % 2 != 1) || ((size / 2) - 1 % 2 != 1))
	{
		cout << "Your size is incorrect. Try again";
		size = -1;
	}
}*/

/*void Transf(int size, int arr[])
{
	int key1, key2;
	int numb = size / 2 - 2;
	int razn = numb - 1;
	int leftpos = size / 2 - 2;
	int rightpos = numb + razn + 1;
	int leftcoord = 1;
	int rightcoord = size/2 - 3;
	int znleft = leftpos + 1;
	int znright = rightpos - 1;
	

	razn++;

	
	cout << arr[leftpos] << " ";

	for (int j = 1; j < size/2-2; j++)
		cout << 0 << " ";

	cout << arr[rightpos] << endl;

	rightpos++;
	leftpos--;

	for (int i = 1; i < size/2-1; i++)
	{	
		cout << arr[leftpos] << " ";
		key1 = 0;
		key2 = 0;

		for (int j = 1; j < size / 2 - 2; j++)
		{
			if (leftcoord < rightcoord)
			{
				if (j == leftcoord)
				{
					cout << arr[znleft] << " ";
					znleft++;
					key1 = 1;
				}
				else
					if (j == rightcoord)
					{
						cout << arr[znright] << " ";
						znright--;
						key2 = 1;
					}
					else
						cout << 0 << " ";
			}
			else
				if (leftcoord == rightcoord && rightcoord == j)
				{
						cout << arr[znright] << " ";
			leftcoord++;
		        }
				else
					 cout << 0 << " ";
		}

		if (key1 == 1)
			leftcoord++;

		if (key2 == 1)
			rightcoord--;

		cout << arr[rightpos] << endl;
	    
		rightpos++;
		leftpos--;

	}
	
}*/