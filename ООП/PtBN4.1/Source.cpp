#include "Func.h"

int main()
{
	User U1;
	Ellipse el1(true, "Red", "Green", 5, 7, 5.6);
	//Ellipse el1;
	//el1.setsize(55);
	//el1.settext("Hello");
	//el1.Print();
	
	
	HyperlinkLabel hp1(true, "https://stackoverflow.com/questions/5135900/stack-around-the-variable-was-corrupted", 5, 8, 25.5, "Question about c++ mistacke", "Green");
	//HyperlinkLabel hp1;
	//TextBox tb1;
	TextBox tb1(true, true, 5, 3, 25.4, "Hello Brother", "White");

	Button but1(true, 8, 3, 99, "Open", "You can click on it");
	//Button but1;

	//User::Print(&el1);
	//cout << endl << endl;
	//U1.Print(&hp1);
	///*hp1.setURL("newurlhz");
	//cout << endl << endl;
	//U1.Print(&hp1);*/

	//cout << endl << endl;
	//U1.Print(&tb1);
	//
	//cout << endl << endl;
	//U1.Print(&but1);
	//

	cout << but1;

	return 0;
}