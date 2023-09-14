#include "Func.h"

int main()
{
	User U;
	DynArray arr(100);
	Ellipse el1(true, "Red", "Green", 5, 7, 5.6);
	HyperlinkLabel hp1(true, "https://stackoverflow.com/questions/5135900/stack-around-the-variable-was-corrupted", 5, 8, 25.5, "Question about c++ mistacke", "Green");
	TextBox tb1(true, true, 5, 3, 25.4, "Hello Brother", "White");
	Button but1(true, 8, 3, 99, "Open", "You can click on it");
	
	arr.push_back(&el1);
	arr.push_back(&hp1);
	arr.push_back(&tb1);
	arr.push_back(&but1);
	arr.del(2);
	arr[2] = tb1;
	//U.Print(&arr[2]);
	cout << endl << endl;
	//U.Print(&tb1);
	cout << endl << endl;
	arr.output();

	return 0;
}