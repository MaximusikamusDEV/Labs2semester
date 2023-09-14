#include "Func.h"

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

void Base::settext(const char* text)
{
	strcpy_s(this->text, 100, text);
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

char* Base::gettext()
{
	return text;
}

Base& Base::operator=(Base& old)
{
	this->size = old.getsize();
	strcpy_s(this->text, 100, text);
	this->X = old.getX();
	this->Y = old.getY();
	this->visible = old.getvis();
	return *this;
}