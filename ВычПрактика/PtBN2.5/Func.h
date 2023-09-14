#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
	char key;
	Node* next;
};

void Output(Node* list, int size);
void Read(Node*& list1, Node*& list2, int& size1, int& size2);
void add(Node*& list, char key);
void Ans(Node*& Endlist, Node*& list, int size1, int size2, int& newsize);
void FromFstToEnd(Node* list, Node*& Endlist, int size1, int& size);
