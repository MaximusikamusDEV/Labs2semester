#pragma once
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
	Node* prev;

	Node(T val = T())
	{
		this->value = val;
		this->next = nullptr;
		this->prev = nullptr;
	}

};

template <typename T>
class List
{
private:
	Node<T>* head;
	Node<T>* tail;
	int m_size;


public:

	List()
	{
		m_size = 0;
		head = nullptr;
		tail = nullptr;
	}

	~List()
	{
		if(m_size != 0)
		Clear();
	}


	List(List<T>& list)
	{
		m_size = list.m_size;
		Node<T>* newel = new Node<T>;

		newel->value = list.head->value;
		newel->prev = nullptr;
		newel->next = nullptr;
		head = newel;

		Node<T>* curr = list.head;
		Node<T>* newcurr = head;
		curr = curr->next;

		while (curr)
		{
			Node<T>* newel = new Node<T>;
			newel->value = curr->value;
			newel->prev = newcurr;
			newel->next = nullptr;
			newcurr->next = newel;
			newcurr = newcurr->next;
			curr = curr->next;
		}

		tail = newel;
	}

	List(List<T>&& list)
	{
		m_size = list.m_size;
		Node<T>* newel = new Node<T>;

		newel->value = list.head->value;
		newel->next = nullptr;
		newel->prev = nullptr;

		head = newel;

		Node<T>* curr = list.head;
		Node<T>* newcurr = head;
		curr = curr->next;

		while (curr)
		{
			Node<T>* newel = new Node<T>;
			newel->value = curr->value;
			newel->next = nullptr;
			newel->prev = newcurr;
			newcurr->next = newel;
			newcurr = newcurr->next;
			curr = curr->next;
		}

		tail = newel;
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
	m_size = list.m_size;
	Node<T>* newel = new Node<T>;

	newel->value = list.head->value;
	newel->next = nullptr;
	newel->prev = nullptr;

	head = newel;

	Node<T>* curr = list.head;
	Node<T>* newcurr = head;
	curr = curr->next;

	while (curr)
	{
		Node<T>* newel = new Node<T>;
		newel->value = curr->value;
		newel->next = nullptr;
		newel->prev = newcurr;
		newcurr->next = newel;
		newcurr = newcurr->next;
		curr = curr->next;
	}

	tail = newel;
	list.~List();
	return *this;
}

template<typename T>
List<T>& List<T>::operator=(List<T>& list)
{
	m_size = list.m_size;
	Node<T>* newel = new Node<T>;

	newel->value = list.head->value;
	newel->next = nullptr;
	newel->prev = nullptr;

	head = newel;

	Node<T>* curr = list.head;
	Node<T>* newcurr = head;
	curr = curr->next;

	while (curr)
	{
		Node<T>* newel = new Node<T>;
		newel->value = curr->value;
		newel->next = nullptr;
		newel->prev = newcurr;
		newcurr->next = newel;
		newcurr = newcurr->next;
		curr = curr->next;
	}

	tail = newel;
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

	if(head->next)
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
		tail = head;
	}
	else
	{
		Node<T>* newel = tail;

		m_size++;
		newel->next = new Node<T>;
		newel = newel->next;
		newel->value = val;
		newel->prev = tail;
		tail = tail->next;
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
	Node<T>* curr = head;
	int indi = 0;
	while (curr && indi < ind)
	{
		curr = curr->next;
		indi++;
	}

	if (!curr)
	{
		cout << "Your num is incorrect.";
		exit(0);
	}

	return curr->value;
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
void ReadFromFile(List<T>& list, int& size)
{
	double num;
	fstream file;
	file.open("In.txt");
	file >> size;

	while (true)
	{
		if (file.eof())
			break;

		file >> num;

		list.push_back(num);
	}


	file.close();
}

template<typename T>
void Ans(List<T> list, int size)
{
	double ans = 1;
	size *= 2;
	size--;

	for (int i = 0; i <= size; i += 2)
	{
		ans *= list[i] - list[size - i];
	}

	cout << "Answer: " << ans;

}
