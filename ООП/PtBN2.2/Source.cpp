#include "Func.h"

int main()
{

	List<char> list1;
	List<char> list2;
	List<char> listfin;
	
	ReadFromFile(list1, list2);

	Ans(list1, list2, listfin);
	
	listfin.Outer();


	return 0;
}