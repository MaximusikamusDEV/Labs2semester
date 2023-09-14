#include "Func.h"

int Matrix::countmatrix = 0;

int main()
{
	Matrix arr(0,0);
	Vector endvect;
	int maxi = 0;

	Read(arr, maxi);
	//cout << arr;
	Ans(arr, endvect, maxi);



	return 0;
}