#include "Func.h"

Vector& Matrix::operator[](int nrow)
{
	if (nrow >= m_row)
		throw;

	return vectpoint[nrow];
}

void Matrix::SetSize(int row)
{
	for (int i = 0; i < row; i++)
	{
		Vector vect(m_col);
		vectpoint[i] = move(vect);
	}
}

void Matrix::push_back(int num)
{
	int i = 0;

	while (true)
	{
		int size = vectpoint[i].GetSize();

		if (size < m_col)
		{
			vectpoint[i].PushBack(num);

			return;
		}
		else
		{
			i++;
		}
		if (i == m_row)
		{
			cout << "There is no enough place in the matrix." << endl;
			return;
		}
	}
}

istream& operator>>(istream& in, Matrix arr)
{
	for (int i = 0; i < arr.m_row; i++)
	{
		for (int j = 0; j < arr.m_col; j++)
			in >> arr[i][j];
	}

	return in;
}

ostream& operator<<(ostream& out, Matrix arr)
{
	cout << "\t" << arr.name << endl;

	for (int i = 0; i < arr.m_row; i++)
	{
		for (int j = 0; j < arr.m_col; j++)
		{
			Vector tmpvect = arr.vectpoint[i];

			if (tmpvect.GetSize() < j)
				out << "\t" << 0 << " ";
			else
				out << "\t" << arr[i][j] << " ";
		}
		out << endl;
	}

	out << endl;

	return out;
}


void Matrix::addrow(int row)
{

	Vector* tmp = new Vector[m_row];

	for (int i = 0; i < m_row; i++)
	{
		tmp[i] = move(vectpoint[i]);
	}

	delete[] vectpoint;
	

	vectpoint = new Vector[row + m_row];
	this->SetSize(row+m_row);

	for (int i = 0; i < m_row; i++)
	{
		vectpoint[i] = move(tmp[i]);
	}


	m_row += row;
	
}


void Matrix::addcol(int ncol)
{
	for (int j = 0; j < ncol; j++)
	{
		for (int i = 0; i < m_row; i++)
		{
			while (ncol + m_col > vectpoint[i].m_size)
			{
				vectpoint[i].SetSize();
			}
			vectpoint[i].m_countEl++;
			vectpoint[i].m_value[j + m_col] = 0;
		}
	}
	m_col += ncol;
}
