#include "Func.h"

void Ans(string& st)
{
	int tmp = 0;
	int ind;
	string newst;

	newst = st;

	for (int i = 0; i < st.length()-1; i++)
	{
		tmp = 0;
		for (int j = i; j < st.length(); j++)
		{
			if (st[i] == st[j] && st[i] != ' ' && st[j] != ' ')
			{
				tmp++;
				if (tmp == 2)
					ind = j;

				if (tmp > 2)
				{
					st[i] = ' ';
					st[ind] = ' ';
					st[j] = ' ';
				}
			}

			

		}

		if (tmp == 2)
		{
			newst[i] = ' ';
			newst[ind] = ' ';
		}

	}


	//cout << st << endl << endl;

	while (true)
	{
		ind = newst.find(' ', 0);
		
		if (ind > newst.length())
			break;

		newst.erase(ind, 1);
	}

	st = newst;

}