#pragma once
#include <iostream>
#include <fstream>
using namespace std;

void ReadArr(int arr[]);
int* Create(int size);
void ReadSize(int& size);
void Output(int arr[], int size);
void Sort(int* arr, int low, int high, int mid);
void Merge(int* arr, int low, int high);

