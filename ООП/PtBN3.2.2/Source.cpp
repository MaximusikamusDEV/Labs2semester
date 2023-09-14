#include "Func.h"

int main()
{
	int size = 3;
	int maxitmp;

	Read(size);

	vector<int> first(size*size);
	vector<vector<int>> second(size, vector<int>(size));
	vector<int> maxi(size*size);

	//cout << size << "   !!!   " << endl << endl;



	Fill(first, second, maxi);

	/*for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << second[i][j] << " ";

		cout << endl;
	}*/

	//cout << maxi[1];

	maxitmp = maxi[0];

	Ans(second, size, maxi);


	cout << "Pointer to pointer" << endl;
	Output(maxi, size);

	ZeroToMax(maxi, maxitmp, size);
	Ans(first, size, maxi);

	cout << endl << "Standart array with shift" << endl;
	Output(maxi, size);


	return 0;
}