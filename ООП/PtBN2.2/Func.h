#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class Node
{
public:
	T value;
	Node* next;

	Node(T val = T(), Node* pnext = nullptr)
	{
		this->value = val;
		this->next = pnext;
	}

};

template <typename T>
class List
{
private:
	Node<T> *head;
	int m_size;


public:
	
	List()
	{
		m_size = 1;
		head = nullptr;
	}

	~List()
	{
		Clear();
	}


	List(List<T>& list)
	{
		m_size = list.m_size;
		Node<T>* newel = new Node<T>;

		newel->value = list.head->value;

		head = newel;

		Node<T>* curr = list.head;
		Node<T>* newcurr = head;
		curr = curr->next;

		while (curr)
		{
			Node<T>* newel = new Node<T>;
			newel->value = curr->value;
			newel->next = nullptr;
			newcurr->next = newel;
			newcurr = newcurr->next;
			curr = curr->next;
		}
	}

	List(List<T>&& list)
	{
		m_size = list.m_size;
		Node<T>* newel = new Node<T>;

		newel->value = list.head->value;

		head = newel;

		Node<T>* curr = list.head;
		Node<T>* newcurr = head;
		curr = curr->next;

		while (curr)
		{
			Node<T>* newel = new Node<T>;
			newel->value = curr->value;
			newel->next = nullptr;
			newcurr->next = newel;
			newcurr = newcurr->next;
			curr = curr->next;
		}

		list.~List();
	}



	List<T>& operator=(List<T>&);
	List<T>& operator=(List<T>&&);
	void push_back(T);
	void Delete(int);
	int FindKey(T);
	T FindNumb(int);
	T& operator[](int ind);
	void Outer();
	void Clear();
	int GetSize();
};

template<typename T>
List<T>& List<T>::operator=(List<T>&& list)
{
	this->~List;

	m_size = list.m_size;
	Node<T>* newel = new Node<T>;

	newel->value = list.head->value;

	head = newel;

	Node<T>* curr = list.head;
	Node<T>* newcurr = head;
	curr = curr->next;

	while (curr)
	{
		Node<T>* newel = new Node<T>;
		newel->value = curr->value;
		newel->next = nullptr;
		newcurr->next = newel;
		newcurr = newcurr->next;
		curr = curr->next;
	}

	list.~List();
	return *this;
}

template<typename T>
List<T>& List<T>::operator=(List<T>& list)
{
	m_size = list.m_size;
	Node<T>* newel = new Node<T>;

	newel->value = list.head->value;

	head = newel;

	Node<T>* curr = list.head;
	Node<T>* newcurr = head;
	curr = curr->next;

	while (curr)
	{
		Node<T>* newel = new Node<T>;
		newel->value = curr->value;
		newel->next = nullptr;
		newcurr->next = newel;
		newcurr = newcurr->next;
		curr = curr->next;
	}

	return *this;
}

template<typename T>
int List<T>::GetSize()
{
	return m_size;
}

template<typename T>
void List<T>::Clear()
{
	Node<T>* pv = head;
	head = head->next;
	while (head)
	{
		delete pv;
		pv = head;
		head = head->next;
	}

	m_size = 0;
}

template<typename T>
T& List<T>::operator[](int ind)
{
	if (ind > m_size - 1)
	{
		cout << "You wrote uncorrect index";
		exit(0);
	}

	Node<T>* curr = head;
	int i = 0;

	while (curr && i < ind)
	{
		curr = curr->next;
		i++;
	}

	if(curr)
	return curr->value;
}

template <typename T>
void List<T>::push_back(T val)
{
	if (!head)
	{
		m_size = 1;
		head = new Node<T>(val);
	}
	else
	{
		Node<T>* newel = head;

		while (newel->next)
		{
			newel = newel->next;
		}

		m_size++;
		newel->next = new Node<T>(val);

	}
}



template <typename T>
void List<T>::Delete(int ind)
{
	Node<T>* curr = head;
	Node<T>* pv = curr->next;
	Node<T>* ppv = curr;
	curr = curr->next->next;
	int curri = 2;

	if (ind == 0)
	{
		delete ppv;
		m_size--;
		head = pv;
		return;
	}

	if (ind == 1)
	{
		ppv->next = curr;
		delete pv;
		m_size--;
		return;
	}

	if (ind > m_size - 1)
	{
		cout << "We can't find ur element";
		return;
	}
	

	while (curri < ind && curr)
	{
		ppv = pv;
		pv = curr;
		curr = curr->next;
		curri++;
	}
	
	if (curr->next)
		pv->next = curr->next;
	else
		pv->next = nullptr;

	delete curr;
	m_size--;
}

template<typename T>
int List<T>::FindKey(T value)
{
	Node<T>* curr = head;
	int num = 0;

	while (curr)
	{
		if (curr->value == value)
		{
			return num;
		}
		num++;
		curr = curr->next;
	}

	return -1;

}

template<typename T>
T List<T>::FindNumb(int ind)
{	
	return head[ind];
}

template<typename T>
void List<T>::Outer()
{
	if (m_size == 0)
	{
		cout << "Your list is clear";
		return;
	}

	Node<T>* curr = head;

	cout << endl;

	while (curr)
	{
		cout << curr->value << " ";
		curr = curr->next;
	}
	cout << endl;
}

template<typename T>
void ReadFromFile(List<T>& list1, List<T>& list2)
{
	fstream file;
	T symb;

	file.open("Input1.txt");

	while (true)
	{

		file >> symb;

		if (file.eof())
			break;

		list1.push_back(symb);
	}

	file.close();

	file.open("Input2.txt");
	while (true)
	{
		file >> symb;
		
		if (file.eof())
			break;

		list2.push_back(symb);	
	}

	file.close();
}

template<typename T>
void Ans(List<T> list1, List<T> list2, List<T>& listfin)
{
	
	for (int i = 0; i < list1.GetSize() - 1; i++)
	{
		if (listfin.FindKey(list1[i]) == -1)
			listfin.push_back(list1[i]);
	}

	for (int i = 0; i < list2.GetSize()-1; i++)
	{
		if (listfin.FindKey(list2[i]) == -1)
			listfin.push_back(list2[i]);
	}

}