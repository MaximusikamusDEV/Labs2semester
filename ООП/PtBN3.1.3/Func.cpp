#include "Func.h"

void Ans(string& st)
{
	string str;
	string tmps;
	int ind = 0;
	int end;
	int tmp;
	st += ' ';

	while (true)
	{
		end = st.find_first_of(",.:; !?-()", ind+1);
		int countgl = 0;
		int countsg = 0;

		for (int i = ind; i < end; i++)
		{
			if (st[i] == 'a' || st[i] == 'o' || st[i] == 'i' || st[i] == 'y' || st[i] == 'e' || st[i] == 'u')
				countgl++;
			else
				countsg++;
		}

		//cout << countgl << " " << countsg << endl << endl;
 
			if (countgl > countsg)
			{
				str.append(st, ind, countgl + countsg);
				str += ' ';
			}

			ind = end + 1;
			if (ind >= st.length())
				break;
	}

	st = str;
}
