#include "Func.h"

Mnozh& Mnozh::operator+(Mnozh& old)
{
	for (auto x : old.mapa)
		mapa[x.first] = true;

	return *this;
}

Mnozh& Mnozh::operator+(string ch)
{

	for(int i = 0; i < ch.size(); i++)
	mapa[ch[i]] = true;

	return *this;
}


Mnozh& Mnozh::operator-(Mnozh& old)
{
	for (auto x : old.mapa)
		mapa[x.first] = false;

	return *this;
}

Mnozh& Mnozh::operator-(string ch)
{
	for (int i = 0; i < ch.size(); i++)
		mapa[ch[i]] = false;
	
	return *this;
}

void Mnozh::push(string st)
{
	for (int i = 0; i < st.size(); i++)
		mapa[st[i]] = true;
}

ostream& operator<<(ostream& out, Mnozh& old)
{
	for (auto x : old.mapa)
	{
		if(x.second == true)
		out << x.first << " ";
	}
	out << endl << endl;

	return out;
}

istream& operator>>(istream& in, Mnozh& old)
{
	string st;
	in >> st;

	for (int i = 0; i < st.size(); i++)
		old.mapa[st[i]] = true;

	return in;
}

