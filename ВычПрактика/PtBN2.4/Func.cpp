#include "Func.h"

struct Node
{
	char val;
	Node* next;

	//Node(char _val) : val(_val), next(nullptr)
	//{}
};

void Add(Node*& L, char st)
{
	Node* newel = new Node;

	newel->val = st;
	newel->next = NULL;

	if (!L)
	{
		L = newel;
	}
	else
	{
			newel->next = L;

			L = newel;	
	}

}

void Read(Node*& L1, Node*& L2)
{

	fstream file;
	char st;

	file.open("Input1.txt");

	while (true)
	{
		file >> st;

		if (file.eof())
			break;

		Add(L1, st);
	}

	file.close();

	file.open("Input2.txt");

	

	while (true)
	{
		file >> st;

		if (file.eof())
			break;


		Add(L2, st);


	}
	file.close();

}

void FromLtoEL(Node* L, Node*& Endl)
{

	bool fl = false;
	Node* head = NULL;

	while (L)
	{
		fl = false;

		if (!Endl)
		{
			Add(Endl, L->val);
			head = Endl;
		}
		while (Endl)
		{
			if (Endl->val == L->val)
			{
				fl = true;
			}

			Endl = Endl->next;

		}

		if (fl == false)
		{
			Endl = head;
			Add(Endl, L->val);
			head = Endl;
		}

		Endl = head;
		L = L->next;
	}

	Endl = head;
}

void Ans(Node* L, Node*& Endl)
{
	
	Node* head = Endl;
	bool fl = false;

	while (L)
	{
		fl = false;

		while (Endl)
		{
			if (Endl->val == L->val)
			{
				fl = true;
			}
			Endl = Endl->next;
		}

		if (fl == false)
		{
			Endl = head;
			Add(Endl, L->val);
			head = Endl;
		}

		Endl = head;
		L = L->next;
	}

	Endl = head;
}

void Output(Node* L1, Node* L2)
{
	while (L1)
	{
		cout << L1->val << " ";
		L1 = L1->next;
	}

	cout << endl << endl;
	cout << "DONE";
	cout << endl << endl;

	while (L2)
	{
		cout << L2->val << " ";
		L2 = L2->next;
	}

	cout << endl << endl;
	cout << "DONE";
	cout << endl << endl;

}

void Output(Node* L)
{
	while (L)
	{
		cout << L->val << " ";
		L = L->next;
	}
}
