#include "Func.h"

void add(Node*& list, char key)
{
	Node* newel = new Node;
	newel->key = key;
	newel->next = NULL;

	if (!list)
	{
		list = newel;
	}
	else
	{
		newel->next = list;
		list = newel;
	}

}

void Read(Node*& list1, Node*& list2, int& size1, int& size2)
{
	char st;
	fstream file;


	file.open("Input1.txt");

	while(!file.eof())
	{
		file >> st;
		
		if (file.eof())
			break;

		list1[size1].key = st;
		list1[size1].next = &list1[size1 + 1];
		size1++;
	}

	file.close();

	file.open("Input2.txt");

	while (!file.eof())
	{
		file >> st;

		if (file.eof())
			break;
		
		list2[size2].key = st;
		list2[size2].next = &list2[size2 + 1];
		size2++;
	}

	file.close();

}

void Ans(Node*& Endlist, Node*& list, int size1, int size2, int& newsize)
{
	bool fl = false;
	int num = size1;

	for (int i = 0; i < size2; i++)
	{
		fl = false;
		int j = 0;


		for (j = 0; j < size1; j++)
		{
			if (Endlist[j].key == list[i].key)
			{
				fl = true;
				break;
			}
		}
			if (fl == false)
			{
				Endlist[num].key = list[i].key;
				Endlist[num - 1].next = &Endlist[num];
				num++;
			}
	}

	newsize = num;

}

void FromFstToEnd(Node* list, Node*& Endlist, int size1, int& size)
{
	bool fl = false;

	for (int i = 0; i < size1; i++)
	{
		fl = false;

		if (!Endlist)
		{
			Endlist[size].key = list[i].key;
			Endlist[size].next = &list[i];
			size++;
		}


		for (int j = 0; j < size; j++)
		{
			if (!Endlist)
				break;

			if (Endlist[j].key == list[i].key)
			{
				fl = true;
			}
		}

		if (fl == false)
		{
			
			Endlist[size].key = list[i].key;
			Endlist[size].next = &list[i];
			size++;
		}
	}
}

void Output(Node* list, int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << list[i].key << " ";
	}

	cout << endl;
}
