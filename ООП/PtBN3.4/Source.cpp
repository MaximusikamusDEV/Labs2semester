#include "Func.h"

//only cifry

int main()
{

	string exp;
	string PolExp;
	int ans = 0;

	cin >> exp;


	PolExp = ToPol(exp);

	cout << PolExp << endl;

	Calc(PolExp, ans);
	cout << ans;


	//A+(B-C)*D-F/(G+H)=
	//A+(B-D)/E*F/Y*(I+Z)=


	return 0;
}