#include "Func.h"

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


char* Button::GetTipText()
{
	return ToolTipText;
}

void ColorC::SetColorC(const char* color)
{
	if (strlen(color) > 50)
	{
		cout << "Size of your color is so big. Change your text with method." << endl;
		strcpy_s(Color, 50, "None");
	}
	else
		strcpy_s(this->Color, 50, color);
}

char* ColorC::GetColorC()
{
	return Color;
}