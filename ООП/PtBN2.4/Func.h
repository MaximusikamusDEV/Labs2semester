#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
private:
	double mod;
	double rad;

public:

	Complex()
	{
		mod = 0;
		rad = 0;
	}

	Complex(int mod, double rad)
	{
		this->mod = mod;
		this->rad = rad;
	}

	Complex(Complex& cmp)
	{
		this->mod = cmp.mod;
		this->rad = cmp.rad;
	}

	Complex(Complex&& cmp)
	noexcept
	{
		mod = cmp.mod;
		rad = cmp.rad;
		cmp.~Complex();
	}

	~Complex()
	{
		mod = 0;
		rad = 0;
	}

	Complex& operator=(Complex&& cmp)
		noexcept
	{
		mod = cmp.mod;
		rad = cmp.rad;
		cmp.~Complex();

		return *this;
	}

	friend ostream& operator<<(ostream& out, Complex cmp)
	{
		out << endl << endl;
		out << cmp.mod << "*(cos" << cmp.rad << "rad) * i(sin" << cmp.rad << "rad)" << endl;
		out << cmp.mod * cos(cmp.rad) << " + i" << sin(cmp.rad);
		out << endl << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Complex& cmp)
	{
		in >> cmp.mod;
		in >> cmp.rad;
		return in;
	}

	Complex& operator=(Complex&);
	Complex& operator^(int);
	Complex& operator+(Complex&);
	Complex& operator-(Complex&);
	Complex& operator*(Complex&);
	Complex& operator/(Complex&);
	Complex& operator|(int);
	void OutForPlusAndMinus();
};


