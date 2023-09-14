#include "Func.h"

int main() 
{
	srand(time(NULL));

	Vector vect;
	int maxi = 0;

	EnterElFile(vect, maxi);

	Vector finvect(maxi);
	
	Ans(vect, finvect, maxi);

	cout << endl << vect;
	
	return 0;
}