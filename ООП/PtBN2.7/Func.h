#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Matrix;

class Vector
{
private:
	int* m_value;
	int m_size;
	int m_countEl;

public:

	~Vector() 
	{
		delete[] m_value;
		m_value = nullptr;
		m_size = 0;
		m_countEl = 0;
	}

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

		vect.~Vector();

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
	friend Matrix;
	friend void Ans(Matrix, Vector&, int);
};


class Matrix
{
private:

	Vector* vectpoint;
	int m_col;
	int m_row;

public:

	static int countmatrix;
	string name;

	Matrix(int row, int col)
	{
		countmatrix++;
		name = "Matrix " + to_string(countmatrix);
		vectpoint = new Vector[row];
		m_col = col;
		m_row = 0;
		this->SetSize(row+m_row);
		m_row += row;
	}

	
	void addcol(int);
	void addrow(int);
	void push_back(int);
	void SetSize(int);
	Vector& operator[](int nrow);
	friend ostream& operator<<(ostream&, Matrix);
	friend istream& operator>>(istream&, Matrix);
	friend void Ans(Matrix, Vector&, int);
};

void Read(Matrix&, int&);