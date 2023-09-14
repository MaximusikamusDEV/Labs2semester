#include "Func.h"

void Vector::SetSize()
{
	if (m_size == 0)
		m_size = 1;

	m_size += 1;

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
	if (ind >= m_size || ind < 0)
	{
		cout << "Exit from vector size";
		throw;
		exit(0);
	}
	else
		if (ind < m_size && ind >= m_countEl)
		{
			m_countEl = ind;

			while (m_countEl > m_size)
			{
				SetSize();
			}

			return m_value[ind];
		} 
		else
			return m_value[ind];
}
