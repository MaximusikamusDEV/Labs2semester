#include "Func.h"
#include "HierarchiralClass.h"

int main()
{

	List<Base*> curr;
	Ellipse el1(true, "Red", "Green", 5, 7, 5.6);
	HyperlinkLabel hp1(true, "https://stackoverflow.com/questions/5135900/stack-around-the-variable-was-corrupted", 5, 8, 25.5, "Question about c++ mistacke", "Green");
	TextBox tb1(true, true, 5, 3, 25.4, "Hello Brother", "White");
	Button but1(true, 8, 3, 99, "Open", "You can click on it");
	

	/*curr.push_back(new Ellipse(true, "Red", "Green", 5, 7, 5.6));
	curr.push_back(new TextBox(true, true, 5, 3, 25.4, "Hello Brother", "White"));
	curr.push_back(new Button(true, 8, 3, 99, "Open", "You can click on it"));*/

	curr.push_back(&el1);
	curr.push_back(&hp1);
	curr.push_back(&tb1);
	curr.Outer();

	//curr.Delete(1);
	
	//curr.Clear();

	//List<Base*> curr2;
	//curr2 = curr;

    curr.Outer();

	return 0;
}