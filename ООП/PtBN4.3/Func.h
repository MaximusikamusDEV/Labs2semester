#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

class Interface
{
public:
	virtual void Print(ostream& out) = 0;
};

class Base : public Interface
{
protected:
	bool visible;
	int X;
	int Y;
	double size;
	int name;

public:

	Base()
	{
		visible = false;
		X = Y = 0;
		size = 0;
		name = 0;
	}

	Base(bool pvisible, int pX, int pY, double psize)
	{
		visible = pvisible;
		X = pX;
		Y = pY;
		size = psize;
		name = 0;
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
	int getname();

};

class Text : public Base
{
private:
	char text[100];
public:


	Text()
	{
		text[0] = '\n';
	}

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

	ColorC()
	{
		Color[0] = '\n';
	}

	void Print(ostream& out) override
	{
		Text::Print(out);
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
	    name = 1;
		setvis(false);
		setXandY(0, 0);
		setsize(0);
		strcpy_s(FillColor, 50, "None");
		strcpy_s(BorderColor, 50, "None");
	};

	Ellipse(bool visible, const char* Fill, const char* Border, int X, int Y, double size)
	{
		name = 1;
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

	//int name = 2;

	HyperlinkLabel()
	{
		name = 2;
		setvis(false);
		setXandY(0, 0);
		setsize(0);
		settext("None");
		SetColorC("None");
		strcpy_s(URL, 500, "None");
	}

	HyperlinkLabel(bool visible, const char* adress, int X, int Y, double size, const char* text, const char* color)
	{
		name = 2;
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
		out << "HyperlinLabel. Type: derivative" << endl;

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

	//int name = 3;

	TextBox()
	{
		name = 3;
		setvis(false);
		setXandY(0, 0);
		setsize(0);
		settext("None");

		SetColorC("None");
		ReadOnly = false;
	}

	TextBox(bool visible, bool ReadOnly, int X, int Y, double size, const char* text, const char* color)
	{
		name = 3;
		if (strlen(color) > 50)
		{
			cout << "Size of your color is so big. Change your text with method." << endl;
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

		cout << endl;

	}
	void SetReadOnly(bool);
};

class Button : public Text
{
private:
	char ToolTipText[500];

public:

	//int name = 4;

	Button()
	{
		name = 4;
		setvis(false);
		setXandY(0, 0);
		setsize(0);
		settext("None");

		strcpy_s(ToolTipText, 500, "None");
	}

	Button(bool visible, int X, int Y, double size, const char* text, const char* ToolTip)
	{
		name = 4;
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
class DynArray
{
private:
	Base** tools;
	int m_size;
	int currsize;
public:

	DynArray(int size = 100)
	{
		tools = new Base*[size];
		m_size = size;
		currsize = 0;

		fstream file;
		file.open("ObjArray.txt");

		while (true)
		{
			int name;
			if (file.eof())
				break;
	
	
			file >> name;
			cout << "!!" << endl;
			//cout << "!!!! " << el.getname() << endl;
			//name = el.getname();
			file.get();
			if (file.eof())
				break;
			if (name == 1)
			{
				Ellipse el;
				file.read((char*)&el, sizeof(Ellipse)-sizeof(int));
				//el.Print(cout);
				file.get();
				tools[currsize] = new Base();
				tools[currsize] = &el;
				currsize++;
			} else
				if (name == 2)
				{
					HyperlinkLabel el;
					file.read((char*)&el, sizeof(HyperlinkLabel)-sizeof(int));
					//el.Print(cout);
					file.get();
					tools[currsize] = new Base();
					tools[currsize] = &el;
					currsize++;

				} else
					if (name == 3)
					{
						TextBox el;
						file.read((char*)&el, sizeof(TextBox)-sizeof(int));
						//el.Print(cout);
						file.get();
						tools[currsize] = new Base();
						tools[currsize] = &el;
						currsize++;

					}
					else
						if(name == 4)
					    {
						   Button el;
						  file.read((char*)&el, sizeof(Button)-sizeof(int));
						  //el.Print(cout);
						  file.get();
						   tools[currsize] = new Base();
						   tools[currsize] = &el;
						   currsize++;
					    }

		}


	}

	DynArray(DynArray& old)
	{
		m_size = old.m_size;
		currsize = old.currsize;
		tools = new Base*[m_size];
		for (int i = 0; i < m_size; i++)
			tools[i] = old.tools[i];
	}

	DynArray(DynArray&& old)
		noexcept
	{
		m_size = move(old.m_size);
		currsize = move(old.currsize);
		tools = new Base*[m_size];
		for (int i = 0; i < m_size; i++)
			tools[i] = move(old.tools[i]);

		old.~DynArray();
	}

	DynArray& operator=(DynArray& old)
	{
		m_size = old.m_size;
		currsize = old.currsize;
		tools = new Base * [m_size];
		for (int i = 0; i < m_size; i++)
			tools[i] = old.tools[i];

		return *this;
	}

	DynArray& operator=(DynArray&& old)
		noexcept
	{
		m_size = move(old.m_size);
		currsize = move(old.currsize);
		tools = new Base*[m_size];
		for (int i = 0; i < m_size; i++)
			tools[i] = move(old.tools[i]);
		
		old.~DynArray();

		return *this;
	}

	~DynArray()
	{

		ofstream file;
		file.open("ObjArray.txt");
		int name = 0;
		int curr = 0;

		while (curr < currsize)
		{
			name = tools[curr]->getname();

			//file.write((char*)&name, sizeof(int));

			file << endl << name << endl;

			if (name == 1)
			{
				file.write((char*)&tools[curr], sizeof(Ellipse));
			}
			else
				if (name == 2)
				{
					file.write((char*)&tools[curr], sizeof(HyperlinkLabel));
				}
				else
					if (name == 3)
					{
						file.write((char*)&tools[curr], sizeof(TextBox));
					}
					else
					{
						file.write((char*)&tools[curr], sizeof(Button));
					}

			curr++;
		}


		delete[] tools;
		tools = nullptr;
		m_size = 0;
		currsize = 0;
	}

	Base* operator[](int ind)
	{
		return tools[ind];
	}

	void push_back(Base*);
	void del_element(int);
	void output();

};

class User
{
public:
	static void Print(Interface* element)
	{
		element->Print(cout);
	}
};
