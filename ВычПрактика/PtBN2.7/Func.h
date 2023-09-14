#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct TREE;
void Read(TREE*& list);
void Add(TREE*& list, int num);
void Find(TREE* list, TREE*& ppv, int num);
void Output(TREE* list);
void Ent(int& n);
void Ans(TREE*& pv, int n, int level, int& ans);
