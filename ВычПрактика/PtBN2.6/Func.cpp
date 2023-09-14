#include "Func.h"

struct Node
{
	double val;
	Node* next;
	Node* prev;
};

void Add(Node*& L1, double tmp)
{
	Node* newel = new Node;

	newel->val = tmp;
	newel->next = NULL;
	newel->prev = NULL;

	if (!L1)
	{
		L1 = newel;
	}
	else
	{
		newel->next = L1;
		L1->prev = newel;
		L1 = newel;
	}
}

void Read(Node*& L1, Node*& L2, int& size)
{
	double tmp;

	fstream file;
	file.open("Input.txt");

	file >> size;

	while (true)
	{

		file >> tmp;
		if (file.eof())
			break;
		Add(L1, tmp);


		file >> tmp;
		if (file.eof())
			break;
		Add(L2, tmp);
	}

	file.close();

}

void Ans(Node*& L1, Node*& L2, int size)
{
	double ans = 1;

	for (int i = 0; i < size - 1; i++)
	{
		L1 = L1->next;
	}

	for (int i = 0; i < size; i++)
	{
		ans *= (L1->val - L2->val);
		L2 = L2->next;
		L1 = L1->prev;
	}
	cout << ans;

}



void Output(Node* L)
{
	while (L)
	{
		cout << L->val << " ";
		
        L = L->next;
	}

	cout << endl;

}