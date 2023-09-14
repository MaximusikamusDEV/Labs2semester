#include "Func.h"

int main()
{
	Ellipse el1(true, "Red", "Green", 5, 7, 5.6);
	HyperlinkLabel hp1(true, "https://stackoverflow.com/questions/5135900/stack-around-the-variable-was-corrupted", 5, 8, 25.5, "Question about c++ mistacke", "Green");
	TextBox tb1(true, true, 5, 3, 25.4, "Hello Brother", "White");
	Button but1(true, 8, 3, 99, "Open", "You can click on it");

	DynArray arr;
	arr.push_back(&el1);
	arr.push_back(&but1);
	arr.push_back(&tb1);
	arr.push_back(&hp1);


	
	//cout << tb1;
	//arr.~DynArray();
	//arr.del_element(2);
	arr.output();

	//DynArray arr2(arr);
	//DynArray arr2;
	//arr2 = arr;
	//arr2 = move(arr);
	//arr.output();
	//arr2.output();
	return 0;
}