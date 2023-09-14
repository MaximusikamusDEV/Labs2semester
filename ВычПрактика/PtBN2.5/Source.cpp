#include "Func.h"

int main()
{

	Node* list1 = new Node[2000];
	Node* list2 = new Node[2000];
	Node* Endlist = new Node[2000];

	int size1 = 0;
	int size2 = 0;
	int newsize = 0;

	Read(list1, list2, size1, size2);

	Output(list1, size1);
	Output(list2, size2);

	FromFstToEnd(list1, Endlist, size1, newsize);

	Ans(Endlist, list2, newsize, size2, newsize);

	Output(Endlist, newsize);

	return 0;
}