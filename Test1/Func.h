#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Vector
{
private:

	int* m_val;
	int size;
	int curr;


public:

	Vector(int size)
	{
		this->size = size;
		curr = 0;
		m_val = new int[size];
	}

	Vector(const Vector& vct)
	{
		size = vct.size;
		m_val = new int[size];
		curr = vct.curr;
		for (int i = 0; i < curr; i++)
			m_val[i] = vct.m_val[i];
	}

	Vector& operator=(const Vector& old)
	{
		curr = old.curr;
		size = old.size;
		for (int i = 0; i < curr; i++)
			m_val[i] = old.m_val[i];

		return *this;
	}

	~Vector()
	{
		size = 0;
		curr = 0;
		delete m_val;
		m_val = nullptr;
	}

	void push_back(int n);
	void out();
	int& operator[](int ind);
	friend ostream& operator <<(ostream&, Vector);
	Vector& operator++(int);
	Vector& operator+(Vector&);
};