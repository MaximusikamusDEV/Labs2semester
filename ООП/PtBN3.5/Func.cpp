#include "Func.h"

void Read(map<string, vector<pair<int, int>>>& fors)
{
	list<int> fstview;
	list<string> maplist;

	string st;
	int num = 0;
	fstream file;
	file.open("Input.txt");
	int globalflag = 0;
	bool add = 0;
	string s;

	while (true)
	{
		if (file.eof())
			break;

		getline(file, st);
		num++;
	    


		if (add == 1)
		{
				add = 0;
				if (st.find('{', 0) == string::npos)
				{
					fors[s].pop_back();
					fors[s].push_back(make_pair(num - 1, num - 1));
				}
				else
				{
					fstview.push_back(num - 1);
					maplist.push_back(s);
					fors[s].pop_back();
				}
		}
		else
			if (st.find("{", 0) != string::npos)
			{
				maplist.push_back("0");
		     	fstview.push_back(num);

				if (st.find("}", 0) != string::npos)
				{
					maplist.pop_back();
					fstview.pop_back();
				}
			} else
				if (st.find("}", 0) != string::npos)
				{
					if (!maplist.empty() && maplist.back() == "0")
					{
						fstview.pop_back();
						maplist.pop_back();
					}
					else
					{
						if(!maplist.empty() && !fstview.empty() && fstview.size() == maplist.size())
						{
							string tmp;
							tmp = maplist.back();
							if (tmp != "0")
							{
								fors[tmp].push_back(make_pair(fstview.back(), num));
							}
							fstview.pop_back();
							maplist.pop_back();
						}
					}
				}
				else
		            Check(st, fors, globalflag, add, s);
	}
}


void Check(string& st, map <string, vector<pair<int, int>>>& fors, int& globalflag, bool& add, string& s)
{
	bool fl = 0;
		if (st.find("/*", 0) != string::npos)
		{
			globalflag++;
			return;
		}
		if (st.find("*/", 0) != string::npos)
		{
			globalflag--;
			return;
		}
		if (st.find("//") != string::npos)
			return;

			int index = 0;
			index = st.find("for", 0);
			int count = 1;

		if (index != string::npos && st[st.find("for", 0) - 1] == '"')
			return;
		else
		{
			for (int i = 0; i < index; i++)
			{
				if (st[i] == '"') count *= -1;
			}

			if (count == -1)
				return;
		}

	for (unsigned int i = 0; i < st.size(); i++)
	{
			index = st.find("for", i);
			if (index != string::npos)
			{
				int endind = 0;
				endind = st.find(')', index);
				string t;
				t.assign(st, index, endind-index+1);
				fors[t].push_back(make_pair(0, 0));
				add = 1;
				s = t;
				break;
			}
	}

}