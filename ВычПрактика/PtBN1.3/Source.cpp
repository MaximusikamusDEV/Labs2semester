#include "Func.h"

int main()
{

	int* arr;
	int size = 5;
	int k;
	int koord;



	arr = Create(size, k);
    
	int n = Find(size, arr, k, koord);

	cout << "Element in the main: " << n << endl << endl;

	ChangeAndOut(arr, size, koord, k);
	

	return 0;
}