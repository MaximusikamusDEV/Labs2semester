#include "Func.h"

void int64::AddMemory(int size)
{
	if (this->m_size == 0)
	{
		this->m_size = 1;
		this->m_val = new int[1];
		m_val[0] = 0;
	}

	int* tmp = m_val;
    
	m_val = new int[size];
	
	for (int i = 0; i < m_size; i++)
		m_val[i] = tmp[i];

	for (int i = m_size; i < size; i++)
		m_val[i] = 0;
	
	m_size = size;


	delete[] tmp;
}

int64& int64::operator=(int64& arr)
{
	m_size = arr.m_size;
	m_val = new int[m_size];
	m_countEl = arr.m_countEl;

	for (int i = 0; i < m_size; i++)
		m_val[i] = arr.m_val[i];

	return *this;
}

int& int64::operator[](int ind)
{
	return m_val[ind];
}

void int64::reverse()
{
	for (int i = m_countEl - 1, j = 0; i > j; j++, i--)
	{
		swap(m_val[j], m_val[i]);
	}

}

int64 int64::operator+(int64& arr)
{
	arr.reverse();
	
	for (int i = 0; i < arr.m_countEl; i++)
	{
		this->plus(arr[i], i);
	}

	arr.reverse();
	return *this;
}

void int64::plus(int ch, int i)
{
	this->reverse();
	int tmp = 0;

	while (true)
	{

		if (i == m_countEl)
			m_countEl++;

		if (i == m_size)
			this->AddMemory(i+1);

			m_val[i] += ch + tmp;
			ch = 0;
			tmp = m_val[i] / 10;
			m_val[i] %= 10;
			i++;

		if (tmp == 0 || i == 64)
		{
			this->reverse();
			break;
		}
	}
}

int64 int64::operator*(int64& arr)
{
	arr.reverse();

	int64 oldthis(*this);
	

	for (int i = 0; i < arr.m_countEl; i++)
	{
		this->mult(arr[i], i, oldthis);
	}

	arr.reverse();

	return *this;
}

void int64::mult(int ch, int dit, int64 oldthis)
{
	int tmp = 0;
	int i = 0;
	int64 multarr(oldthis);
	//multarr.AddMemory(64);
	multarr.reverse();

	while (true)
	{
		if (i == multarr.m_size-1)
			multarr.AddMemory(i + 2);

		multarr[i] = multarr[i] * ch + tmp;
		tmp = multarr[i] / 10;
		multarr[i] %= 10;

		i++;

		if (i == 64 || i == multarr.m_countEl)
		{
			if (i == 64)
			{
				multarr.AddMemory(64);
			}

			if (i == multarr.m_size)
				multarr.AddMemory(i + 1);

			if (tmp != 0)
			{
				multarr[i] = tmp;
				multarr.m_countEl++;
			}


			for (int j = 0; j < dit; j++)
			{
				if (multarr.m_countEl+1 > multarr.m_size)
					multarr.AddMemory(multarr.m_countEl + 1);

				for (i = 0; i <= multarr.m_countEl; i++)
				{
					if (i == 0)
					{
						tmp = multarr[i];
						multarr[i] = 0;
					}
					else
					{
						swap(multarr[i], tmp);
					}
				}
				multarr.m_countEl++;
			}

			multarr.reverse();
          
			if (dit == 0)
				*this = multarr;
			else
				*this + multarr;

			return;
		}
	}
}