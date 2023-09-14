#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <list>
#include <vector>
using namespace std;
void Read(map<string, vector<pair<int, int>>>&);
void Check(string& st, map <string, vector<pair<int, int>>>& fors, int& globalflag, bool&, string&);