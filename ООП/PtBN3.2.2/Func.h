#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void Read(int& size);
void Fill(vector<int>& arr, vector<vector<int>>& arr2, vector<int>& maxi);
void Ans(vector<vector<int>>& arr, int size, vector<int>& maxi);
void Output(vector<int>& maxi, int size);
void Ans(vector<int> arr, int size, vector<int>& maxi);
void ZeroToMax(vector<int>& maxi, int maxitmp, int size);