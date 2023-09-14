#include "Func.h"

int main()
{

	Node* List = NULL;
	Node* ans = NULL;

	Read(List);

	int n;

	cin >> n;

	cout << "First" << endl;
	Output(List);

	Ans(List, n, ans);

	cout << endl << "After Operations" << endl;
	Output(List);

	cout << endl << "Our Students" << endl;
	Output(ans);

	return 0;
}