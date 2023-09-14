#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
struct Node;
void Add(Node*& L, char st);
void Read(Node*& L1, Node*& L2);
void Output(Node* L1, Node* L2);
void Ans(Node*, Node*&);
void FromLtoEL(Node* L, Node*& Endl);
void Output(Node* L);
