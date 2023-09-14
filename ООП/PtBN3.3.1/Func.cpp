#include "Func.h"

void Read(list<char>& lst1, list<char>& lst2)
{
	fstream file;

	file.open("Input1.txt");

	char t;

	while (true)
	{

		file >> t;

		if (file.eof())
			break;

		lst1.push_back(t);
	}

	file.close();

	file.open("Input2.txt");

	while (true)
	{
		file >> t;
		
		if (file.eof())
			break;

		lst2.push_back(t);
	}

	file.close();
}

void Ans(list<char> lst1, list<char> lst2, list<char>& endlst)
{
	lst1.sort();
	lst2.sort();

	endlst.merge(lst1);
	endlst.merge(lst2);

	endlst.unique();
}

void Output(list<char> lst)
{
	list<char>::iterator beg = lst.begin();

	while (beg != lst.end())
	{
		cout << *beg << " ";
		beg++;
	}
}