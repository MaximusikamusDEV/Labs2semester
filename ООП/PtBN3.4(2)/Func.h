#pragma once
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
string ToPol(string exp, vector<int>& nums);
void CheckPrior(int& prior, char exp);
void Calc(string st, int& ans, vector<int> nums);
