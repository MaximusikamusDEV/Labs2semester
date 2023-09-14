#include "Func.h"

struct Node
{
	char Sname[100];
	char Fname[100];
	char date[100];
	int course;
	double mark;
	Node* next;
};

void FindPlace(Node*& list, Node*& ppv, char sname[])
{
	Node* pv = list;
	ppv = list;
	while (pv && pv->Sname[0] < sname[0])
	{
		ppv = pv;
		pv = pv->next;
	}
}

void Add(Node*& list, char sname[], char fname[], char date[], int course, double mark)
{
	Node* newel = new Node;
	Node* ppv = NULL;
	for (int i = 0; i < 100; i++)
	{
		newel->Sname[i] = sname[i];
		newel->Fname[i] = fname[i];
		newel->date[i] = date[i];
	}
	newel->mark = mark;
	newel->course = course;
	newel->next = NULL;

	if (!list)
	{
		list = newel;
	}
	else
	{
		if (list->Sname[0] >= sname[0])
		{
			newel->next = list;
			list = newel;
		}
		else
		{
			FindPlace(list, ppv, sname);
			newel->next = ppv->next;
			ppv->next = newel;
		}
	}

}


void Read(Node*& list)
{
	char sname[100];
	char fname[100];
	char date[100];
	int course = 0;
	int count = 0;
	int i = 0;
	double mark = 0;

	fstream file;
	file.open("Input.txt");



	while (!file.eof())
	{
		file >> sname;
		file >> fname;
		file >> date;
		file >> course;
		file >> mark;
	  	
		Add(list, sname, fname, date, course, mark);
	}



	file.close();

}


void Output(Node* list)
{
	while (list)
	{
		cout << list->Sname << " ";
		list = list->next;
	}
}

void Ans(Node*& list, int n, Node*& ans)
{
	
	Node* pv;
	Node* tmp;
	list = list->next;
	pv = list;
	list = list->next;

	bool fl = false;

 
	while (pv && pv->course == n)
	{
		Add(ans, pv->Sname, pv->Fname, pv->date, pv->course, pv->mark);
		tmp = pv;
		pv = pv->next;
		delete tmp;
		list = list->next;
	}

		tmp = pv;

	while (list)
	{
		fl = false;
		if (list->course == n)
		{
			Add(ans, list->Sname, list->Fname, list->date, list->course, list->mark);
			
			pv->next = list->next;
			list = list->next;
			fl = true;
		}
		if (fl == false)
		{
			list = list->next;
			pv = pv->next;

		}
	}

	list = tmp;
}