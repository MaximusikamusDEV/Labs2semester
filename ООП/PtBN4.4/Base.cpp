#include "Func.h"
#include "HierarchiralClass.h"

void Base::setvis(bool vis)
{
	visible = vis;
}

void Base::setXandY(int X, int Y)
{
	this->X = X;
	this->Y = Y;
}

void Base::setsize(double size)
{
	this->size = size;
}

void Text::settext(const char* text)
{
	strcpy_s(this->text, 100, text);
	//this->text = text;
}

bool Base::getvis()
{
	return visible;
}

int Base::getX()
{
	return X;
}

int Base::getY()
{
	return Y;
}

double Base::getsize()
{
	return size;
}

char* Text::gettext()
{
	return text;
}

ostream& operator<<(ostream& out, Base& old)
{
	old.Print(out);
	return out;
}


void operator delete(void* pointer)
{
	cout << endl << endl << "There was freed memory from class object" << endl << endl;
	free(pointer);
}