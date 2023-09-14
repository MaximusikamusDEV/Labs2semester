#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

void Clear(char*);

class Interface
{
public:
	virtual void Print() = 0;
	virtual int getname() = 0;
	virtual ~Interface() = default;
};

class Base : public Interface
{
private:
	bool visible;
	int X;
	int Y;
	double size;
	char text[100];
	int name = 1;

public:


	Base()
	{
		visible = false;
		X = Y = 0;
		size = 0;
		text[0] = '\n';
	}

    ~Base()
	{
		visible = false;
		X = Y = 0;
		size = 0;
		Clear(text);
	}

	int getname() override
	{
		return name;
	}

	void setname(int oldname)
	{
		name = oldname;
	}

	void Print() override
	{
		if (visible == 0)
			cout << "unvisible ";
		else
			cout << "visible ";

		cout << endl;
		cout << "X and Y: " << X << " " << Y << endl;
		cout << "Size: " << size << endl;
		cout << "Text: " << text << endl;
	}

	Base& operator=(Base&);

	void setvis(bool);
	void setXandY(int, int);
	void setsize(double);
	void settext(const char*);

	bool getvis();
	int getX();
	int getY();
	double getsize();
	char* gettext();
};

class Ellipse : public Base
{
private:
	char FillColor[50];
	char BorderColor[50];

public:


	Ellipse()
	{
		this->setname(2);
		setvis(false);
		setXandY(0, 0);
		setsize(0);
		strcpy_s(FillColor, 50, "None");
		strcpy_s(BorderColor, 50, "None");
	};

	Ellipse(bool visible, const char* Fill, const char* Border, int X, int Y, double size)
	{
		this->setname(2);
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

	~Ellipse()
	{
		Clear(BorderColor);
		Clear(FillColor);
		Base::~Base();
	}

	void Print() override
	{
		cout << "Ellipse. Type: derivative" << endl;

		bool visible = getvis();
		int X = getX();
		int Y = getY();
		double size = getsize();

		if (visible == 0)
			cout << "unvisible ";
		else
			cout << "visible ";

		cout << endl;
		cout << "X and Y: " << X << " " << Y << endl;
		cout << "Size: " << size << endl;

		cout << "Fill and Border colors: " << FillColor << " " << BorderColor << endl;
	}

	void setcolors(const char*, const char*);
};


class HyperlinkLabel: public Base
{
private:
	char URL[500];
	char Color[50];
public:


	HyperlinkLabel()
	{
		this->setname(3);
		setvis(false);
		setXandY(0, 0);
		setsize(0);
		settext("None");
		
		strcpy_s(Color, 50, "None");
		strcpy_s(URL, 500, "None");
	}

	HyperlinkLabel(bool visible, const char* adress, int X, int Y, double size, const char* text, const char* color)
	{
		this->setname(3);
		if (strlen(adress) > 500)
		{
			cout << "Size of your adress is so big. Change your text with method." << endl;
			strcpy_s(URL, 500, "None");
		}
		else
			strcpy_s(URL, 500, adress);

		if (strlen(color) > 50)
		{
			cout << "Size of your color is so big. Change your text with method." << endl;
			strcpy_s(Color, 50, "None");
		}
		else
			strcpy_s(this->Color, 50, color);

		setvis(visible);
		setXandY(X, Y);
		setsize(size);
		settext(text);

	}

	~HyperlinkLabel()
	{
		Clear(URL);
		Clear(Color);
		Base::~Base();
	}

	void Print() override
	{
		cout << "HyperlinLabel. Type: derivative" << endl;

		Base::Print();

		cout << "URL: " << URL << endl;
		cout << "Color: " << Color << endl;
	}

	void setURL(const char*);
	void SetColor(const char*);
};

class TextBox: public Base
{
private:
	bool ReadOnly;
	char Color[50];

public:


	TextBox()
	{
		this->setname(4);
		setvis(false);
		setXandY(0, 0);
		setsize(0);
		settext("None");

		strcpy_s(Color, 50, "None");
		ReadOnly = false;
	}

	TextBox(bool visible, bool ReadOnly, int X, int Y, double size, const char* text, const char* color)
	{
		this->setname(4);
		if (strlen(color) > 50)
		{
			cout << "Size of your color is so big. Change your text with method." << endl;
			strcpy_s(Color, 50, "None");
		}
		else
			strcpy_s(this->Color, 50, color);

		setvis(visible);
		setXandY(X, Y);
		setsize(size);
		settext(text);
		
		this->ReadOnly = ReadOnly;
	}

	~TextBox()
	{
		Clear(Color);
		ReadOnly = false;
		Base::~Base();
	}

	void Print() override
	{
		cout << "TextBox. Type: derivative" << endl;

		Base::Print();

		if (ReadOnly == 0)
			cout << "Can't be changed by User";
		else
			cout << "Can be changed by User";

		cout << endl;

		cout << "Color: " << Color << endl;
	}

	void SetColor(const char*);
	void SetReadOnly(bool);
};

class Button : public Base
{
private:
	char ToolTipText[500];

public:


	Button()
	{
		this->setname(5);
		setvis(false);
		setXandY(0, 0);
		setsize(0);
		settext("None");

		strcpy_s(ToolTipText, 500, "None");
	}

	Button(bool visible, int X, int Y, double size, const char* text, const char* ToolTip)
	{
		this->setname(5);
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

	~Button()
	{
		Clear(ToolTipText);
		Base::~Base();
	}

	Button& operator=(Button&);

	void Print() override
	{
		cout << "Button. Type: derivative" << endl;

		Base::Print();

		cout << "ToolTipText: " << ToolTipText << endl;
	}

	char* getToolTip();
	void setToolTip(const char*);
};

class DynArray
{
private:
	Interface** tools;
	int size;
	int curr;

public:

	DynArray(int size)
	{
		curr = 0;
		tools = new Interface*[size];
		this->size = size;
	}

	~DynArray()
	{
		for (int i = 0; i < curr; i++)
			tools[i]->~Interface();

		delete tools;
		tools = nullptr;
		curr = 0;
		size = 0;
	}

	void push_back(Interface*);
	void del(int ind);
	void output();
	Interface& operator[](int ind);

};


class User
{
public:
	void Print(Interface* element)
	{
		element->Print();
	}
};