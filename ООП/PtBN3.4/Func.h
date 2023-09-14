#pragma once
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
#include <list>

using namespace std;
string ToPol(string exp);
void CheckPrior(int& prior, char exp);
void Calc(string st, int& ans);