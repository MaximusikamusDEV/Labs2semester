#include "Func.h"

int main()
{
	int size;
	cin >> size;
	int n;

	Vector vct(size);

	for (int i = 0; i < size; i++)
	{
		cin >> n;
		vct.push_back(n);
	}

	Vector vct2(vct);
	vct++;

	cout << "!!!! " << vct << endl;

	vct2 + vct;

	cout << vct2;
	cout << endl << endl;
	Vector vct3(size);


	vct3 = vct2;

	cout << vct3;

	return 0;
}