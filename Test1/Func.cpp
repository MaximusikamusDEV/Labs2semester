#include "Func.h"

void Vector::push_back(int n)
{
	m_val[curr] = n;
	curr++;
}

void Vector::out()
{
	for (int i = 0; i < curr; i++)
		cout << m_val[i] << " ";
}

int& Vector::operator[](int ind)
{
	return m_val[ind];
}

ostream& operator<<(ostream& out, Vector vct)
{
	for (int i = 0; i < vct.curr; i++)
		out << vct.m_val[i] << " ";

	return out;
}


Vector& Vector::operator++(int d)
{
	

	for (int i = 0; i < curr; i++)
		this->m_val[i] += 10;

	return *this;
}

Vector& Vector::operator+(Vector& vct)
{
	for (int i = 0; i < vct.curr; i++)
		this->m_val[i] += vct.m_val[i];

	return *this;
}