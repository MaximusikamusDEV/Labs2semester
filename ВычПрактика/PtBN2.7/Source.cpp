#include "Func.h"

int main()
{
	TREE* list = NULL;
	int n;
	int ans = 0;
	int level = 0;

	Read(list);

	TREE* head = list;
 
	Ent(n);

	Ans(list, n, level, ans);

	cout << ans;

	return 0;
}