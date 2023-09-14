#include "Func.h"

int main()
{

	Node* L1 = NULL;
	Node* L2 = NULL;
	Node* L = NULL;



	Read(L1, L2);

	FromLtoEL(L1, L);

	Ans(L2, L);

	Output(L);

	return 0;
}