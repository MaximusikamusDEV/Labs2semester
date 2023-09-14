#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Vector
{
private:
	  int* m_value;
	  int m_size;
	  int m_countEl;

public:

	~Vector(){}
	
	Vector()
	{
		m_size = 0;
		m_value = new int[0];
		m_countEl = 0;
	}

	Vector(int size)
	{
		m_size = size;
		m_value = new int[size];
		m_countEl = 0;

		for (int i = 0; i < size; i++)
			m_value[i] = 0;

	}

	Vector(Vector& vect)
	{
		m_countEl = vect.m_countEl;
		m_size = vect.m_size;

		m_value = new int[m_size];

		for (int i = 0; i < m_size; i++)
			m_value[i] = vect.m_value[i];
	}
	
	Vector(Vector&& vect) 
	noexcept
	{
		swap(m_countEl, vect.m_countEl);
		swap(m_size, vect.m_size);
		m_value = new int[m_size];

		for (int i = 0; i < m_size; i++)
			m_value[i] = vect.m_value[i];

		vect.m_value = nullptr;
		vect.m_countEl = 0;
		vect.m_size = 0;
	}	

	Vector& operator=(Vector&& vect) noexcept
	{
		swap(m_countEl, vect.m_countEl);
		swap(m_size, vect.m_size);
		m_value = new int[m_size];

		for (int i = 0; i < m_size; i++)
			m_value[i] = vect.m_value[i];

		return *this;
	}

	friend ostream& operator<<(ostream& out, Vector vect)
	{
		for (int i = 0; i < vect.GetSize(); i++)
			out << vect[i] << " ";

		return out;
	}

	void SetSize();
	int GetSize();
	void PushBack(int);
	int& operator[](int);
	Vector& operator=(Vector&);
};

void EnterElFile(Vector&, int&);
void EnterElRand(Vector&, int&);
void Ans(Vector, Vector&, int);