#include "Func.h"

int main()
{
	int size;
	int arr[10000];
	int** darr;

	

	Enter(arr, size);
	darr = Create(size);
	Fill(size, darr);
	Outer(size, darr);
	cout << endl;
	Put(size, darr, arr);
	Outer(size, darr);


	return 0;
}