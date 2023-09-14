#include "Func.h"
Complex& Complex::operator=(Complex& cmp)
{
	mod = cmp.mod;
	rad = cmp.rad;

	return *this;
}

void Complex::OutForPlusAndMinus()
{
	cout << endl << endl;
	cout << mod << " + i" << rad;
	cout << endl << endl;
}

Complex& Complex::operator^(int n)
{
	mod = pow(mod, n);
	rad = rad * n;

	return *this;
}

Complex& Complex::operator+(Complex& cmp)
{
	mod = mod * cos(rad) + cmp.mod * cos(cmp.rad);
	rad = sin(rad) + sin(cmp.rad);
	return *this;
}

Complex& Complex::operator-(Complex& cmp)
{
	mod = mod * cos(rad) - cmp.mod * cos(cmp.rad);
	rad = sin(rad) - sin(cmp.rad);
	return *this;
}

Complex& Complex::operator*(Complex& cmp)
{
	mod = mod * cmp.mod;
	rad = rad + cmp.rad;
	return *this;
}

Complex& Complex::operator/(Complex& cmp)
{
	mod = mod / cmp.mod;
	rad = rad - cmp.rad;
	return *this;
}

Complex& Complex::operator|(int n)
{
	Complex cmp;

	for (int i = 0; i < n; i++)
	{
		cmp.mod = pow(abs(mod), 1 / n);
		cmp.rad = (rad + 2 * 3.14 * i) / n;
		cout << cmp;
	}

	return *this;
}
