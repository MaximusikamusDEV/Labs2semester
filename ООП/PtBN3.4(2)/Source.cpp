#include "Func.h"

int main()
{
	string exp;
	string PolExp;
	int ans = 0;
	vector<int> nums;

	cin >> exp;

	PolExp = ToPol(exp, nums);

	Calc(PolExp, ans, nums);
	cout << ans;

	//A+(B-C)*D-F/(G+H)=
	//A+(B-D)/E*F/Y*(I+Z)=
	//11+5*(25/5*3)-5*(3*4/2)= 56
	//29-56/2*4-45*(2-3+8*45)= -16238
	//63/7*3*4*(5*6*7*7)=  158760
	//25%5+5*3-(8*9)= -57

	return 0;
}