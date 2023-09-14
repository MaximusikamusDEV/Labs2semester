#include "Func.h"

int main()
{

	int wordcnt = 0, maxi = 0;
	int numbs[20000];
	int maxsize = 0;

	Read(wordcnt, maxi, maxsize);
	Result(numbs, wordcnt, maxi, maxsize);
	Write(numbs, wordcnt, maxi);



	return 0;
}

