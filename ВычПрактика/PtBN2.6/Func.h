#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct Node;

void Output(Node* L);
void Read(Node*& L1, Node*& L2, int&);
void Add(Node*& L1, double tmp);
void Ans(Node*& L1, Node*& L2, int size);