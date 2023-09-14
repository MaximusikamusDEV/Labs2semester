#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct Node;
void Output(Node* list);
void Read(Node*& pl, Node*& min);
void Add(Node*& list, int n);
void Ans(Node* pl, Node* min);