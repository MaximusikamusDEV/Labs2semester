#include "Func.h"

int main()
{

	int* arr1;
	int** arr2;
	int* maxi;
	int size = 0;
	int maxitmp;



	Read(size);

	

	arr2 = Create(size, 1);
	arr1 = Create(size);
	maxi = Create(size);

	Fill(arr1, arr2, maxi);

	maxitmp = maxi[0];

	Ans(arr2, size, maxi);


	cout << "Pointer to pointer" << endl;
	Output(maxi, size);

	maxi = Create(size);
	
	ZeroToMax(maxi, maxitmp, size);
	Ans(arr1, size, maxi);

	cout << endl <<"Standart array with shift" << endl;
	Output(maxi, size);





	return 0;
}