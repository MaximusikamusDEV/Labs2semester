#include "Func.h"

void Clear(char* st)
{
	for (unsigned int i = 0; i < strlen(st); i++)
		st[i] = ' ';
}

void Ellipse::setcolors(const char* Fill, const char* Border)
{

	if (strlen(Fill) > 50)
	{
		cout << "Size of your FillColor is so big. Change your text with method." << endl;
	}
	else
	{
		for (unsigned int i = 0; i < strlen(FillColor); i++)
			FillColor[i] = ' ';

		FillColor[0] = '\n';

		strcpy_s(FillColor, 50, Fill);
	}

	if (strlen(Border) > 50)
	{
		cout << "Size of your BorderColor is so big. Change your text with method." << endl;
	}
	else
	{
      for (unsigned int i = 0; i < strlen(BorderColor); i++)
		BorderColor[i] = ' ';

	   BorderColor[0] = '\n';
	   
	   strcpy_s(BorderColor, 50, Border);
	}
		
}

void HyperlinkLabel::setURL(const char* newurl)
{
	if (strlen(newurl) > 500)
	{
		cout << "Size of your adress is so big. Change your text with method." << endl;

	}
	else
	{
		for (unsigned int i = 0; i < strlen(URL); i++)
			URL[i] = ' ';

		URL[0] = '\n';

		strcpy_s(URL, 500, newurl);
	}
}

void TextBox::SetReadOnly(bool Read)
{
	ReadOnly = Read;
}

void TextBox::SetColor(const char* Color)
{
	if (strlen(Color) > 50)
	{
		cout << "Size of your color is so big. Change your text with method." << endl;
	}
	else
	{
		for (unsigned int i = 0; i < strlen(this->Color); i++)
			this->Color[i] = ' ';

		this->Color[0] = '\n';

		strcpy_s(this->Color, 50, Color);
	}
}

void Button::setToolTip(const char* ToolTip)
{
	if (strlen(ToolTip) > 500)
	{
		cout << "Size of your text is so big. Change your text with method." << endl;
	}
	else
	{
		for (unsigned int i = 0; i < strlen(ToolTipText); i++)
			ToolTipText[i] = ' ';

		ToolTipText[0] = '\n';

		strcpy_s(ToolTipText, 500, ToolTip);
	}
}

char* Button::getToolTip()
{
	return ToolTipText;
}

Button& Button::operator=(Button& old)
{
	Base::operator=(old);
	strcpy_s(ToolTipText, 500, old.getToolTip());

	return *this;
}

void HyperlinkLabel::SetColor(const char*)
{
	if (strlen(Color) > 50)
	{
		cout << "Size of your color is so big. Change your text with method." << endl;
	}
	else
	{

		for (unsigned int i = 0; i < strlen(this->Color); i++)
			this->Color[i] = ' ';

		this->Color[0] = '\n';

		strcpy_s(this->Color, 50, Color);
	}
}



void DynArray::push_back(Interface* old)
{
	//Interface* old = pvold;
	this->curr++;
	if (curr >= size)
	{
		cout << "we can't add any objects";
		return;
	}

	int name = old->getname();


	if (name == 2)
	{
		tools[curr-1] = new Ellipse();
		tools[curr-1] = old;
	} 
	if (name == 3)
	{
		tools[curr - 1] = new HyperlinkLabel();
		tools[curr - 1] = old;
	}
	if (name == 4)
	{
		tools[curr - 1] = new TextBox();
		tools[curr - 1] = old;
	}
	if (name == 5)
	{
		tools[curr - 1] = new Button();
		tools[curr - 1] = old;
	}
}

Interface& DynArray::operator[](int ind)
{
	return *tools[ind];
}

void DynArray::del(int ind)
{
	if (ind == curr)
	{
		curr--;
	   return;
    }

	for(int i = ind; i < curr-1; i++)
	tools[i] = tools[i + 1];

	curr--;
	//tools[ind]->~Interface();
}

void DynArray::output()
{
	User U;
	for (int i = 0; i < curr; i++)
	{
		U.Print(tools[i]);
		cout << endl << endl;
	}
}
