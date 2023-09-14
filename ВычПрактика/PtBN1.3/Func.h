#pragma once
#include <iostream>
#include <fstream>
using namespace std;
int* Create(int& size, int& k);
int& Find(int& size, int arr[], int& k, int& koord);
void ChangeAndOut(int arr[], int size, int koord, int k);