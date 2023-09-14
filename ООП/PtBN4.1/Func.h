#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Interface
{
public:
	virtual void Print(ostream& out) = 0;
};

class Base : public Interface
{
private:
	bool visible;
	int X;
	int Y;
	double size;

public:

	Base()
	{
		visible = false;
		X = Y = 0;
		size = 0;
	}

	void Print(ostream& out) override
	{
		if (visible == 0)
			out << "unvisible ";
		else
			out << "visible ";

		out << endl;
		out << "X and Y: " << X << " " << Y << endl;
		out << "Size: " << size << endl;
		
	}

	friend ostream& operator<<(ostream&, Base&);

	void setvis(bool);
	void setXandY(int, int);
	void setsize(double);
	

	bool getvis();
	int getX();
	int getY();
	double getsize();

};

class Text : public Base
{
private:
	char text[100];
public:
	void Print(ostream& out) override
	{
		Base::Print(out);
		out << "Text: " << text << endl;
	}
	void settext(const char*);
	char* gettext();
};

class ColorC : public Text
{
private: 
	char Color[50];
public:
	void Print(ostream& out) override
	{
		Text::Print(out);
		out << "Text: "  << endl;
	}

	void SetColorC(const char*);
	char* GetColorC();
};


class Ellipse : public Base
{
private:
	char FillColor[50];
	char BorderColor[50];

public:

	Ellipse()
	{
		setvis(false);
		setXandY(0, 0);
		setsize(0);
		strcpy_s(FillColor, 50, "None");
		strcpy_s(BorderColor, 50, "None");
	};

	Ellipse(bool visible, const char* Fill, const char* Border, int X, int Y, double size)
	{
		setvis(visible);
		setXandY(X, Y);
		setsize(size);
		
		if (strlen(Fill) > 50)
		{
			cout << "Size of your FillColor is so big. Change your text with method." << endl;
			strcpy_s(FillColor, 50, "None");
		}
		else
			strcpy_s(FillColor, 50, Fill);
		
		if (strlen(Border) > 50)
		{
			cout << "Size of your BorderColor is so big. Change your text with method." << endl;
			strcpy_s(BorderColor, 50, "None");
		}
		else
			strcpy_s(BorderColor, 50, Border);

	}

	void Print(ostream& out) override
	{
		out << "Ellipse. Type: derivative" << endl;

		Base::Print(out);

		out << "Fill and Border colors: " << FillColor << " " << BorderColor << endl;
	}

	void setcolors(const char*, const char*);
};


class HyperlinkLabel: public ColorC
{
private:
	char URL[500];
	
public:

	HyperlinkLabel()
	{
		setvis(false);
		setXandY(0, 0);
		setsize(0);
		settext("None");
		SetColorC("None");
		strcpy_s(URL, 500, "None");
	}

	HyperlinkLabel(bool visible, const char* adress, int X, int Y, double size, const char* text, const char* color)
	{
		SetColorC(color);
		if (strlen(adress) > 500)
		{
			cout << "Size of your adress is so big. Change your text with method." << endl;
			strcpy_s(URL, 500, "None");
		}
		else
			strcpy_s(URL, 500, adress);

		

		setvis(visible);
		setXandY(X, Y);
		setsize(size);
		settext(text);

	}

	void Print(ostream& out) override
	{
		out << "HyperLinkLable. Type: derivative" << endl;

		ColorC::Print(out);

		out << "URL: " << URL << endl;
	}

	void setURL(const char*);
};

class TextBox: public ColorC
{
private:
	bool ReadOnly;

public:

	TextBox()
	{
		setvis(false);
		setXandY(0, 0);
		setsize(0);
		settext("None");

		SetColorC("None");
		ReadOnly = false;
	}

	TextBox(bool visible, bool ReadOnly, int X, int Y, double size, const char* text, const char* color)
	{
		if (strlen(color) > 50)
		{
			cout << "Your written size is so big. Try it again please." << endl;
			SetColorC("None");
		}
		else
			SetColorC(color);

		setvis(visible);
		setXandY(X, Y);
		setsize(size);
		settext(text);
		
		this->ReadOnly = ReadOnly;
	}

	void Print(ostream& out) override
	{
		out << "TextBox. Type: derivative" << endl;

		ColorC::Print(out);

		if (ReadOnly == 0)
			out << "Can't be changed by User";
		else
			out << "Can be changed by User";

	}
	void SetReadOnly(bool);
};

class Button : public Text
{
private:
	char ToolTipText[500];

public:
	Button()
	{
		setvis(false);
		setXandY(0, 0);
		setsize(0);
		settext("None");

		strcpy_s(ToolTipText, 500, "None");
	}

	Button(bool visible, int X, int Y, double size, const char* text, const char* ToolTip)
	{
		if (strlen(ToolTip) > 500)
		{
			cout << "Size of your text is so big. Change your text with method." << endl;
			strcpy_s(ToolTipText, 500, "None");
		} 
		else
		    strcpy_s(ToolTipText, 500, ToolTip);


		setvis(visible);
		setXandY(X, Y);
		setsize(size);
		settext(text);
	}

	void Print(ostream& out) override
	{
		cout << "Button. Type: derivative" << endl;

	
		Text::Print(out);

		out << "ToolTipText: " << ToolTipText << endl;
	}

	void setToolTip(const char*);
	char* GetTipText();
};


class User
{
public:
	static void Print(Interface* element)
	{
		element->Print(cout);
	}
};