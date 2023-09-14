#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template<typename T>
class Node
{
public:
	T val;
	Node* right;
	Node* left;

	Node(T val = T(), Node* right = nullptr, Node* left = nullptr)
	{
		this->val = val;
		this->right = right;
		this->left = left;
	}

};

template<typename T>
class Tree
{
private:
	Node<T>* head;
public:

	Tree()
	{
		head = nullptr;
	}

	Tree(Tree& list)
	{
			this->Run(list.GetHead());
	}

	Tree(Tree<T>&& list)
	{
			this->Run(list.GetHead());
		    list.~Tree();
	}

	~Tree()
	{
		DelTree(head);
	}

	Tree& operator=(Tree& list)
	{
		this->~Tree();
		this->Run(list.GetHead());

		return *this;
	}

	Tree& operator=(Tree&& list)
	{
		this->~Tree();
		this->Run(list.GetHead());
		list.~Tree();

		return *this;
	}

	Node<T>* FindEl(T);
	Node<T>* GetHead();
	void Run(Node<T>*);
	void Outer();
	void Add(T);
	void Delete(T key);
};

template<typename T>
Node<T>* Tree<T>::FindEl(T el)
{
	Node<T>* curr = head;

	while (true)
	{
		if (el > curr->val)
			curr = curr->right;
		else
			if (el < curr->val)
				curr = curr->left;
			else
				return curr;
	}
}

template<typename T>
void DelTree(Node<T>*& curr)
{
	if (!curr)
		return;
	DelTree(curr->left);
	DelTree(curr->right);
	delete curr;
	curr = NULL;
}

template<typename T>
Node<T>* Tree<T>::GetHead()
{
	return head;
}

template<typename T>
void Tree<T>::Delete(T key)
{
	Node<T>* curr = head;
	Del(curr, key);
}

template<typename T>
void Del(Node<T>*& list, T key)
{
	
	Node<T>* pv = list;



	while (true)
	{
		if (key > list->val)
		{
			if (list->right->val == key)
				pv = list;

			list = list->right;
		}
		else
			if (key < list->val)
			{
				if (list->left->val == key)
					pv = list;

				list = list->left;
			}
			else
				if (key == list->val)
				{
					if (!list->right && !list->left)
					{
						if (pv->left == list)
							pv->left = nullptr;
						else
							pv->right = nullptr;
						
						delete list;
					} else
						if (!list->left && list->right)
						{
							pv->right = list->right;
							delete list;
						}
						else 
							if (list->left && !list->right)
							{
								pv->left = list->left;
								delete list;
							}
							else
							{
								Node<T>* tmp = list;
								Node<T>* ppv = list->right;
								list = list->right;
								if (list->left)
								{
									list = list->left;
									while (true)
									{
										if (!list)
											break;

										ppv = list->left;
										list = list->left;
									}
								}

								ppv->left = nullptr;
								tmp->val = list->val;
								if (list->right)
									tmp->right = list->right;
								else
									tmp->right = nullptr;
								delete list;
							}
					return;
				}
	}
}


template<typename T>
void Tree<T>::Add(T el)
{
	Push_back(head, el);
}

template<typename T>
void Tree<T>::Outer()
{
	if (!head || head == NULL)
	{
		cout << "Empty head";
		return;
	}
	else
	Out(head);
}

template <typename T>
void Out(Node<T>* curr)
{
	if (!curr)
		return;

	Out(curr->left);

	cout << curr->val << " ";

	Out(curr->right);


}

template<typename T>
void Tree<T>::Run(Node<T>* curr)
{
	if (!curr)
		return;

	if (curr->left)
		Run(curr->left);

	if (curr->right)
		Run(curr->right);

	Push_back(head, curr->val);
}

template<typename T>
void Push_back(Node<T>*& list, T el)
{
	if (!list)
	{
		Node<T>* newel = new Node<T>;
		newel->val = el;
		list = newel;
		return;
	}

		Node<T>* tmp = list;

		while (list)
		{
			if (list->val < el)
			{
				if (list->right)
				{
					list = list->right;
				}
				else
				{
					Node<T>* newel = new Node<T>;
					newel->val = el;
					list->right = newel;
					list = tmp;
					return;
				}
			}
			else
			{
				if (list->left)
				{
					list = list->left;
				}
				else
				{
					Node<T>* newel = new Node<T>;
					newel->val = el;
					list->left = newel;
					list = tmp;
					return;
				}
			}
		}
}

template<typename T>
void Read(Tree<T>& list)
{
	T el;
	fstream file;
	file.open("Input2.txt");

	while (true)
	{
		if (file.eof())
			break;

		file >> el;
		list.Add(el);
	}

	file.close();
}

template<typename T>
void Ans(Node<T>* list, int num, int i, int& ans)
{
	if (!list)
		return;


	if (i == num)
		ans++;

	Ans(list->left, num, i + 1, ans);
	Ans(list->right, num, i + 1, ans);
}