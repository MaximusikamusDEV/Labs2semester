#include "Func.h"

void DynArray::push_back(Base* element)
{
	tools[currsize] = new Base();
	tools[currsize] = element;
	currsize++;
}

void DynArray::output()
{
	for (int i = 0; i < currsize; i++)
	{
		User::Print(tools[i]);
		cout << endl << endl;
	}
}

void DynArray::del_element(int ind)
{
	if (ind == currsize-1)
	{
		//cout << "tut";
		//tools[ind] = new Base();
		//tools[ind] = tools[ind + 1];
		currsize--;
		return;
	}

	for (int i = ind; i < currsize - 1; i++)
		tools[i] = tools[i + 1];

	currsize--;
}