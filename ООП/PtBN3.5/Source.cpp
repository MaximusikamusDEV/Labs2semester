#include "Func.h"

int main()
{
	map <string, vector<pair<int, int>>> fors;

	Read(fors);

	for (auto it : fors)
	{
		cout << it.first << endl;
		vector<pair<int, int>> vct;
		vct = it.second;
		for (auto x : vct)
			cout << x.first << " " << x.second << endl;

		cout << endl;
	}


	return 0;
}