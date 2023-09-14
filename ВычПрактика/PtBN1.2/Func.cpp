#include "Func.h"

char wordarr[1000][1000];

void Read(int& wordcnt, int& maxi, int& maxsize)
{
	ifstream file;
	file.open("Input.txt");

	char st[200];

	int maxisize = 0;

	while (!file.eof())
	{
		file.getline(st, sizeof(st), ' ');
		//cout << strlen(st) << endl;
		int i;
		i = strlen(st) - 1;

		if (st[i] == ' ' ||
			st[i] == '.' ||
			st[i] == ',' ||
			st[i] == ';' ||
			st[i] == ':' ||
			st[i] == '!' ||
			st[i] == '?' ||
			st[i] == '(' ||
			st[i] == ')' ||
			st[i] == '-'
			)
		{
			
			st[i] = '\0';

		}

			maxisize = i;

		if (maxisize > maxsize)
			maxsize = i+1;

		for (int j = 0; j < sizeof(st); j++)
		{
			if (st[j] == '\0')
				break;
			
			wordarr[wordcnt][j] = st[j];
		}
		wordcnt++;
	    


	}

	file.close();
}


void Result(int numbs[], int& wordcnt, int& maxi, int maxsize)
{


	for (int i = 0; i < wordcnt-1; i++)
	{
		numbs[i] = 1;

		for (int j = i+1; j < wordcnt; j++)
			if (strncmp(wordarr[j], wordarr[i], maxsize) == 0 && wordarr[i][0] != '*' && wordarr[j][0] != '*')
			{
				numbs[i]++;
				if (numbs[i] > maxi)
					maxi = numbs[i];
				wordarr[j][0] = '*';
			}
	}

	
	
	if (wordarr[wordcnt-1][0] != '*')
	{
		numbs[wordcnt-1] = 1;
		if (numbs[wordcnt-1] > maxi)
			maxi = numbs[wordcnt-1];
		cout << maxi << endl;
	}

}

void Write(int numbs[], int& wordcnt, int& maxi)
{
	for (int i = 0; i < wordcnt; i++)
	{
		if (numbs[i] == maxi)
			cout << wordarr[i] << " ";
       
		//cout << numbs[i] << endl;

	}
}