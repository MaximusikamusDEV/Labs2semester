#include "Func.h"
struct TREE
{
	int key;
	TREE* left;
	TREE* right;
};

void Ans(TREE*& pv, int n, int level, int& ans)
{
		if (pv && level < n)
		{
			level++;

			if (pv->left)
			{
				Ans(pv->left, n, level, ans);
			}

			if (pv->right)
			{
				Ans(pv->right, n, level, ans);
			}
		}
		else
     		if (pv && level == n)
	    		ans++;

}

void Ent(int& n)
{
	cout << "Enter a level you wanna know: ";
	cin >> n;
}

void Add(TREE*& list, int num)
{
	TREE* ppv = NULL;
	TREE* newel = new TREE;
	newel->left = NULL;
	newel->right = NULL;
	newel->key = num;

	if (!list)
	{
		list = newel;
	}
	else
	{
		Find(list, ppv, num);
		if (ppv->key > num)
			ppv->left = newel;
		else
			ppv->right = newel;
	}
}

void Find(TREE* list, TREE*& ppv, int num)
{
	ppv = list;

	while (list)
	{
		ppv = list;

		if (list->key > num)
			list = list->left;
		else
			list = list->right;
	}
}

void Read(TREE*& list)
{
	int num;
	TREE* ppv = NULL;
	fstream file;

	file.open("Input3.txt");

	while (true)
	{
		file >> num;

		Add(list, num);

		if (file.eof())
			break;
	}

	file.close();
}


void Output(TREE* list)
{
	if (list)
	{
		Output(list->left);
		cout << list->key << " ";
		Output(list->right);
	}
}