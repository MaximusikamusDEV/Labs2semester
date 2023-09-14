#include "Header.h"

int main()
{
	Tree<int> ls;

	Read(ls);

	int num;
	int ans = 0;
	cout << "Write a num: ";
	cin >> num;


	Ans(ls.GetHead(), num, 0, ans);

	cout << ans;


	return 0;
}