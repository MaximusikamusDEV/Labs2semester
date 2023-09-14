#include "Func.h"

void Ans(string& st)
{
	stringstream cont;
	int tmp = 0;
	int j = 0;
	int ch = 0;
	for (int i = st.length() - 1; i >= 0; i--)
	{
		if (st[i] == 'A') tmp += 10 * pow(16, j);
		else
			if (st[i] == 'B') tmp += 11 * pow(16, j);
			else
				if (st[i] == 'C') tmp += 12 * pow(16, j);
				else
					if (st[i] == 'D') tmp += 13 * pow(16, j);
					else
						if (st[i] == 'E') tmp += 14 * pow(16, j);
						else
							if (st[i] == 'F') tmp += 15 * pow(16, j);
							else
							{
								cont.clear();
								cont << st[i];
								cont >> ch;
								tmp += ch * pow(16, j);
							}
		j++;
		
	}

	cout << tmp << " ";

}