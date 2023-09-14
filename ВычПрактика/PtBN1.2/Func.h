#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


void Read(int& wordcnt, int& maxi, int& maxsize);
void Result(int numbs[], int& wordcnt, int& maxi, int maxsize);
void Write(int numbs[], int& wordcnt, int& maxi);