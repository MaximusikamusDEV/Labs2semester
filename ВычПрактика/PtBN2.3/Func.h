#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;
struct Node;
void Read(Node*& list);
void Output(Node* list);
void Read(Node*& list);
void Add(Node*& list, char sname[], char fname[], char date[], int course, double mark);
void FindPlace(Node*& list, Node*& ppv, char sname[]);
void Ans(Node*& list, int n, Node*& ans);
