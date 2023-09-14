#include "Func.h"

struct Node
{
	int zn;
	Node* next;
};

void Add(Node*& list, int n)
{
	Node* new_el = new Node;

	new_el->zn = n;
	new_el->next = NULL;

	if (!list)
	{
		list = new_el;
		return;
	}

	list->next = new_el;
	list = list->next;

}

void Read(Node*& pl, Node*& min)
{
	int n;
	bool fl1 = false, fl2 = false;
	Node* headpl = NULL;
	Node* headmin = NULL;
	fstream file;

	file.open("Input.txt");

	while (true)
	{
		if (file.eof())
			break;

		file >> n;
		if (n > 0)
		{
			Add(pl, n);
			if (fl1 == false)
			{
				headpl = pl;
				fl1 = true;
			}
		}
		else
			if (n < 0)
			{
				Add(min, n);
				if (fl2 == false)
				{
					headmin = min;
					fl2 = true;
				}
			}
	}

	file.close();

	pl = headpl;
	min = headmin;

}

void Output(Node* list)
{
	while (list)
	{
		cout << list->zn << " ";
		list = list->next;
	}
}

void Ans(Node* pl, Node* min)
{
	bool fl = false;
	ofstream file;
	file.open("Output.bin");

	while (true)
	{
		if (!pl && !min)
			break;

		if (fl == false)
		{
			file.write(reinterpret_cast<char*>(&pl->zn), sizeof(int));
			pl = pl->next;
			fl = true;
		}
		else
		{
			file.write(reinterpret_cast<char*>(&min->zn), sizeof(int));
			min = min->next;
			fl = false;
		}
	}


	file.close();
}

void Output()
{
	int n;
	fstream file;
	file.open("Output.bin");
	while (true)
	{
		file.read(reinterpret_cast<char*>(&n), sizeof(int));

		if (file.eof())
			break;

		cout << n << " ";
	}

	file.close();

}