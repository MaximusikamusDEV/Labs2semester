#include "Func.h"

void Read(list<double> & lst, int& size)
{
	fstream file;
	double n;

	file.open("Input.txt");

	file >> size;

	while (true)
	{
		//cout << "1111";
		
	
		if (file.eof())
			break;

		file >> n;


		lst.push_back(n);
		

	}

	file.close();
}

void Ans(list<double> & lst, int size)
{
	list<double>::iterator beg = lst.begin();
	list<double>::reverse_iterator endi = lst.rbegin();
	double ans = 1;
	int count = 0;
	int fl = 1;

	while (count < size)
	{

		if (count % 2 == 0)
			fl = 1;
		else
			fl = -1;

		ans *= (*beg*fl - *endi*fl);
		beg++;
		beg++;
		endi++;
		endi++;
		count++;
	}

	cout << ans;
}

void Output(list<double> lst)
{
	//list<double>::iterator beg = lst.begin();
	list<double>::reverse_iterator beg = lst.rbegin();

	while (beg != lst.rend())
	{
		cout << *beg << " ";
		beg++;
	}
}