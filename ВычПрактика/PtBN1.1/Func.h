#pragma once
#include <iostream>
#include <fstream>
using namespace std;
void Enter(int arr[], int& size);
void Put(int size, int** darr, int arr[]);
void Fill(int size, int** darr);
void Outer(int size, int** darr);
int** Create(int size);