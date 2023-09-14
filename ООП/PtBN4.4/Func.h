#pragma once
#include "HierarchiralClass.h"
#include <iostream>
#include <string>
#include <string.h>
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
	Node<T>* head;
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

	while (head)
	{
		head = head->next;
		
		delete[] pv;
		pv = nullptr;
		pv = head;
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

	if (curr)
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
		cout << *curr->value << endl << endl;
		curr = curr->next;
	}
	cout << endl;
}



