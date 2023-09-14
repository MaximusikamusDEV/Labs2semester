#include "Func.h"

void Read(vector<int>& vect)
{
	fstream file;

	file.open("Input.txt");
	int tmp;

	while (true)
	{
		if (file.eof())
			break;

		file >> tmp;
		vect[tmp]++;
	}

	file.close();

}


void Ans(vector<int> vect)
{
	Read(vect);

	for (int i = 0; i < vect.size(); i++)
		if (vect[i] > 1)
			cout << i << " ";
}