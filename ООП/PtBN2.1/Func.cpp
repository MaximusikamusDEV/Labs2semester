#include "Func.h"

void Vector::SetSize()
{
	if (m_size == 0)
		m_size = 1;

	m_size *= 2;

	int* tmp = m_value;

	m_value = new int[m_size];

	for (int i = 0; i < m_size; i++)
		m_value[i] = tmp[i];

	delete[] tmp;
}

int Vector::GetSize()
{
	return m_countEl;
}

void Vector::PushBack(int ch)
{
	while (m_countEl >= m_size)
	{
		SetSize();
	}

    m_value[m_countEl] = ch;
	m_countEl++;
}

Vector& Vector::operator=(Vector& vect)
{
	m_countEl = vect.m_countEl;
	m_size = vect.m_size;

	m_value = new int[m_size];

	for (int i = 0; i < m_size; i++)
		m_value[i] = vect.m_value[i];

	return *this;
}

int& Vector::operator[](int ind)
{
	if (ind > m_size || ind < 0)
	{
    	cout << "Exit from vector size";
		exit(0);
	}
	else
	return m_value[ind];
}



void Ans(Vector vect, Vector& finvect, int maxi)
{
	int tmp = 0;

	for (int i = 0; i < vect.GetSize(); i++)
	{
		tmp = vect[i];
		
		finvect[tmp]++;

	
	}


	for (int i = 0; i < maxi; i++)
	{
		if (finvect[i] > 1)
			cout << i << " ";
	}

}

void EnterElFile(Vector& vect, int& maxi)
{
	int ch = 0;
	fstream file;
	file.open("Input.txt");

	while (true)
	{
		if (file.eof())
			break;

		file >> ch;
		maxi = max(maxi, ch);
		
		vect.PushBack(ch);

		if (file.eof())
			break;
	}
	file.close();

}

void EnterElRand(Vector& vect, int& maxi)
{
	int size;
	int ch = 0;
	cout << "Write a num of elements: ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		ch = rand() % 100;
		maxi = max(maxi, ch);
		vect.PushBack(ch);
	}

}