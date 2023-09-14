#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class int64
{
private:

	int* m_val;
	int m_size;
	int m_countEl;

public:
    
	int64()
	{
		m_size = 0;
		m_countEl = 0;
		m_val = new int(0);
	}

	int64(int* arr, int size, int countEl)
	{
		m_size = size;
		m_countEl = countEl;
		m_val = new int[size];

		for (int i = 0; i < size; i++)
			m_val[i] = arr[i];
	}

	int64(int64& arr)
	{
		m_size = arr.m_size;
		m_val = new int[m_size];
		m_countEl = arr.m_countEl;

		for (int i = 0; i < m_size; i++)
			m_val[i] = arr.m_val[i];
	}

	int64(int64&& arr)
	noexcept
	{
		m_size = arr.m_size;
		m_val = new int[m_size];
		m_countEl = arr.m_countEl;

		for (int i = 0; i < m_size; i++)
			m_val[i] = arr.m_val[i];

		arr.~int64();
	}

	~int64()
	{
		m_countEl = 0;
		m_size = 0;
		delete[] m_val;
		m_val = nullptr;
	}


	friend istream& operator>>(istream& in, int64& arr)
	{
		char num[64];

		in >> num;
		int i = 0;

		while (num[i])
		{
			if (i + 1 > arr.m_size && i < 64)
			{
				arr.AddMemory(i + 1);
				arr.m_val[i] = (int)num[i] - 48;
				arr.m_countEl++;
				i++;
			}
			else
				i++;
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, int64 arr)
	{
		if (arr.m_size == 0)
		{
			cout << "Empty int64";
			return out;
		}

		for (int i = 0; i < arr.m_countEl; i++)
		{
			out << arr.m_val[i];
		}

		return out;
	}

	int64& operator=(int64&& arr)
		noexcept
	{
		swap(m_size, arr.m_size);
		m_val = new int[m_size];
		swap(m_countEl, arr.m_countEl);

		for (int i = 0; i < m_size; i++)
			swap(m_val[i], arr.m_val[i]);

		arr.~int64();

		return *this;
	}

	int64& operator=(int64&);
	void AddMemory(int);
	int& operator[](int ind);
	void reverse();
	int64 operator+(int64&);
	void plus(int, int);
	int64 operator*(int64&);
	void mult(int, int, int64);
};