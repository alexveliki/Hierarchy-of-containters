#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Container.h"
#include "Stack.cpp"
#include "Queue.cpp"
#include "DoubleLinkedList.cpp"

template<typename T>
struct Element{
	Container<T>* con;
	Element<T>* next;
};


template<class T>
class HeterogeneousLinkedList{
	Element<T>* start;
	size_t size;

	void copy(const HeterogeneousLinkedList<T>& other);
	void clear();
	


public:
	HeterogeneousLinkedList();
	HeterogeneousLinkedList(ifstream& file, int n); // 1
	~HeterogeneousLinkedList();
	HeterogeneousLinkedList<T>& operator=(const HeterogeneousLinkedList&);

	void push(Container<T>*);
	void remove();
	bool empty();
	
	bool checkContain(const T&);                    // 3
	void addToSmallest(const T&);                   // 4
	void filter(Condition);					        // 6
	void sortAll();								    // 7
	void printAll();								// 8
	void iterateAllSorted();						// 9
	Container<T>* findElement(const T&);			// 10
	void printToFile(ofstream& file);               // 11
};

template <typename T>
void HeterogeneousLinkedList<T>::copy(const HeterogeneousLinkedList<T>& other)
{
	Element<T>* it = other.start;
	while (it)
	{
		add(it->con);
		it = it->next;
	}
}

template <typename T>
void HeterogeneousLinkedList<T>::clear()
{
	while (!empty())
	{
		remove();
	}
}
template <typename T>
HeterogeneousLinkedList<T>& HeterogeneousLinkedList<T>::operator=(const HeterogeneousLinkedList& other)
{
	if (this != other)
	{
		clear();
		copy(other);
	}
	return *this;
}

template <typename T>
HeterogeneousLinkedList<T>::HeterogeneousLinkedList()
{
	start = NULL;
	size = 0;
}

template <typename T>
HeterogeneousLinkedList<T>::HeterogeneousLinkedList(ifstream& fin, int n)
{
	size = 0;
	start = NULL;
	char type;
	string elementType;
	T x;
	for (int i = 0; i < n; i++)
	{
		fin >> type;
		//fin >> elementType;
		if (type == 'Q')
		{
			Queue<T>* q = new Queue<T>;
			while (fin.get() == ' ')
			{
				fin >> x;
				q->add(x);
			}
			push(q);
		}
		else if (type == 'S')
		{
			Stack<T>* s = new Stack<T>;
			while (fin.get() == ' ')
			{
				fin >> x;
				s->add(x);
			}
			Stack<T>* rs = new Stack<T>;
			while (!s->empty())
			{
				rs->add(s->getElement());
				s->remove();
			}
			delete s;
			push(rs);
		}
		else if (type == 'D')
		{
			DoubleLinkedList<T>* d = new DoubleLinkedList<T>;
			while (fin.get() == ' ')
			{
				fin >> x;
				d->add(x);
			}
			push(d);
		}
	}
	fin.close();
}

template <typename T>
HeterogeneousLinkedList<T>::~HeterogeneousLinkedList()
{
	while (!empty())
	{
		remove();
	}
}

template <typename T>
void HeterogeneousLinkedList<T>::push(Container<T>* c)
{
	Element<T>* temp=new Element<T>;
	temp->con = c;
	temp->next = NULL;

	if (!start)
	{
		start = temp;
	}
	else
	{
		Element<T>* it;
		it = start;
		while (it)
		{
			if (!it->next)
			{
				it->next = temp;
				break;
			}
			it = it->next;
		}
	}
	size++;
}

template <typename T>
void HeterogeneousLinkedList<T>::remove()
{
	if (!empty())
	{
		Element<T>* temp = start->next;
		delete start;
		start = temp;
		size--;
	}
}

template <typename T>
bool HeterogeneousLinkedList<T>::empty()
{
	return start == NULL;
}

template <typename T>
bool HeterogeneousLinkedList<T>::checkContain(const T& x)
{
	Element<T>* it;
	it = start;
	while (it)
	{
		if (it->con->member(x))
		{
			return true;
		}
		it = it->next;
	}
	
	return false;
}

template <typename T>
void HeterogeneousLinkedList<T>::addToSmallest(const T& x)
{
	Element<T>* mn = start;
	Element<T>* it = start;
	while (it)
	{
		if (mn->con->getSize() > it->con->getSize())
		{
			mn = it;
		}
		it = it->next;
	}
	mn->con->add(x);
}

template <typename T>
void HeterogeneousLinkedList<T>::filter(Condition f)
{
	if (!empty())
	{
		Element<T>* it;
		it = start;
		while (it)
		{
			if (it->con->getType() == "S")
			{
				Stack<T>* temp = new Stack<T>;
				while (!it->con->empty())
				{
					if (!f(it->con->getElement()))
					{
						temp->add(it->con->getElement());
					}
					it->con->remove();
				}
				while (!temp->empty())
				{
					it->con->add(temp->getElement());
					temp->remove();
				}
				delete temp;
			}
			else
			{
				Queue<T>* temp = new Queue<T>;
				while (!it->con->empty())
				{
					if (!f(it->con->getElement()))
					{
						temp->add(it->con->getElement());
					}
					it->con->remove();
				}
				while (!temp->empty())
				{
					it->con->add(temp->getElement());
					temp->remove();
				}
				delete temp;
			}
			it = it->next;
		}
	}
}


template <typename T>
void HeterogeneousLinkedList<T>::sortAll()
{
	if (!empty())
	{
		Element<T>* it;
		it = start;
		while (it)
		{
			it->con->sort();
			it = it->next;
		}
	}
}

template <typename T>
void HeterogeneousLinkedList<T>::printAll()
{
	if (!empty())
	{
		Element<T>* it;
		it = start;
		while (it)
		{
			it->con->print();
			it = it->next;
		}
	}
}


template <typename T>
void HeterogeneousLinkedList<T>::iterateAllSorted()
{
	vector<Container<T>*> v;
	bool flag = false;
	if (!empty())
	{
		flag = true;
		Element<T>* it;
		it = start;
		while (it)
		{
			
			Queue<T>* temp = new Queue<T>;
			while (!it->con->empty())
			{
				temp->add(it->con->getElement());
				it->con->remove();
			}
			v.push_back(temp);
			it = it->next;
		}
	}

	int mn,id;
	while (flag)
	{
		flag = false;
		for (size_t i = 0; i < v.size(); i++)
		{
			if (v[i]->getSize() > 0)
			{
				if (!flag)
				{
					flag = true;
					mn = v[i]->getElement();
					id = i;
				}
				else if (mn > v[i]->getElement()) 
				{
					mn = v[i]->getElement();
					id = i;
				}
			}
		}
		v[id]->remove();
		cout << mn << " ";
		Element<T>* it = start;
		for (int i = 0; i < id; i++)
		{
			it = it->next;
		}
		it->con->add(mn);
	}
	cout << endl;

	for (int i = 0; i < v.size(); i++)
	{
		delete v[i];
	}


	// fix stack order
	if (!empty())
	{
		flag = true;
		Element<T>* it;
		it = start;
		while (it)
		{
			if (it->con->getType() == "S")
			{
				Queue<T>* temp = new Queue<T>;
				while (!it->con->empty())
				{
					temp->add(it->con->getElement());
					it->con->remove();
				}
				while (!temp->empty())
				{
					it->con->add(temp->getElement());
					temp->remove();
				}

			}
			it = it->next;
		}
	}
}


template <typename T>
Container<T>* HeterogeneousLinkedList<T>::findElement(const T& x)
{
	Container<T>* ans = NULL;
	if (!empty())
	{
		Element<T>* it;
		it = start;
		while (it && !ans)
		{
			if (it->con->member(x))
			{
				ans = it->con;
			}
			it = it->next;
		}
	}
	return ans;
}

template <typename T>
void HeterogeneousLinkedList<T>::printToFile(ofstream& fout)
{
	if (!empty())
	{
		Element<T>* it;
		it = start;
		while (it)
		{
			it->con->printToFile(fout);
			it = it->next;
		}
	}
}