#pragma once
#include <iostream>
#include <fstream>
using namespace std;

int** Create(int size, int k);
int* Create(int size);
void Read(int& size);
void Fill(int arr[], int* arr2[], int maxi[]);
void Ans(int* arr[], int size, int maxi[]);
void Output(int maxi[], int size);
void Ans(int arr[], int size, int maxi[]);
void ZeroToMax(int maxi[], int maxitmp, int size);