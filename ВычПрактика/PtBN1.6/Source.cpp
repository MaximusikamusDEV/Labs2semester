#include "Func.h"

int main()
{

	int* arr;
	int size;

	ReadSize(size);
	arr = Create(size);
	ReadArr(arr);

	//Output(arr, size);

	Merge(arr, 0, size - 1);

	Output(arr, size);








	return 0;
}