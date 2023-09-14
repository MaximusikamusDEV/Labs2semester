#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class Mnozh
{
private:

	map<char, bool> mapa;

public:

	void push(string);
	Mnozh& operator+(Mnozh&);
	Mnozh& operator-(Mnozh&);
	Mnozh& operator+(string);
	Mnozh& operator-(string);
	friend ostream& operator <<(ostream&, Mnozh&);
	friend istream& operator >>(istream&, Mnozh&);
};