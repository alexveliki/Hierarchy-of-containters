#pragma once

#include "Container.h"
#include <iostream>
using namespace std;

template<typename T>
struct DllElement {
	T data;
	DllElement<T>* prev;
	DllElement<T>* next;
};


template <typename T>
class DoubleLinkedList : public Container<T>
{
	DllElement<T>* start;
	DllElement<T>* end;
	size_t size;

	void copy(const DoubleLinkedList<T>&);
	void clear();

public:
	DoubleLinkedList();
	~DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList&);
	DoubleLinkedList& operator=(const DoubleLinkedList&);

	bool empty();
	void print();
	void printToFile(ofstream&);
	void sort();

	void addToFront(const T&);
	void remove();
	void add(const T&);
	void removeFromBack();	

	size_t getSize();
	string getType();
	T getElement();

	bool member(T const&);
	bool checkCond(Condition);
};


template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	start = NULL;
	end = NULL;
	size = 0;
}


template <typename T>
void DoubleLinkedList<T>::copy(const DoubleLinkedList& other)
{
	DllElement<T>* temp = other.start;
	while (temp)
	{
		add(temp->data);
		temp = temp->next;
	}
}

template <typename T>
void DoubleLinkedList<T>::clear()
{
	while (!empty())
	{
		remove();
	}
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList& other)
{
	copy(other);
}

template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList& other)
{
	if (this != other)
	{
		clear();
		copy(other);
	}
	return *this;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	clear();
}

template <typename T>
void DoubleLinkedList<T>::addToFront(const T& elem)
{
	DllElement<T>* temp = new DllElement<T>;
	temp->data = elem;
	if (empty())
	{
		start = end = temp;
		temp->prev = temp->next = NULL;
	}
	else
	{
		temp->prev = NULL;
		temp->next = start;
		start = temp;
	}
	size++;
}

template <typename T>
void DoubleLinkedList<T>::add(const T& elem)
{
	DllElement<T>* temp = new DllElement<T>;
	temp->data = elem;
	if (empty())
	{
		start = end = temp;
		temp->prev = temp->next = NULL;
	}
	else
	{
		end->next = temp;
		temp->prev = end;
		temp->next = NULL;
		end = temp;
	}
	size++;
}

template <typename T>
void DoubleLinkedList<T>::remove()
{
	if (!empty())
	{
		if (getSize() == 1)
		{
			delete start;
			start = NULL;
			end = NULL;
		}
		else
		{
			DllElement<T>* temp = start;
			start = temp->next;
			delete temp;
			start->prev = NULL;
		}
		size--;
	}
}

template <typename T>
void DoubleLinkedList<T>::removeFromBack()
{
	if (!empty())
	{
		DllElement<T>* temp = end;
		end = temp->prev;
		delete temp;
		end->next = NULL;
		size--;
	}
}

template<typename T>
size_t DoubleLinkedList<T>::getSize()
{
	return size;
}

template<typename T>
string DoubleLinkedList<T>::getType()
{
	return "D";
}

template<typename T>
T DoubleLinkedList<T>::getElement()
{
	return start->data;
}

template <typename T>
bool DoubleLinkedList<T>::empty()
{
	return start == NULL;
}

template <typename T>
void DoubleLinkedList<T>::print()
{
	if (empty())
		cout << "Empty list" << endl;
	else
	{
		cout << "Double linked list: ";
		DllElement<T>* it = start;
		while (it)
		{
			cout << it->data << " ";
			it = it->next;
		}
		cout << endl;
	}
}

template <typename T>
void DoubleLinkedList<T>::printToFile(ofstream& fout)
{
	if (!empty())
	{
		fout << "D ";
		//fout << this->getElementType() << " ";
		DllElement<T>* it = start;
		while (it)
		{
			fout << it->data << " ";
			it = it->next;
		}
		fout << endl;
	}
}

template <typename T>
bool DoubleLinkedList<T>::member(T const& x)
{
	DllElement<T>* it;
	it = start;
	while (it)
	{
		if (it->data == x)
		{
			return true;
		}
		it = it->next;
	}
	return false;
}

template <typename T>
bool DoubleLinkedList<T>::checkCond(Condition f)
{
	if (empty())
	{
		return false;
	}
	else
	{
		DllElement<T>* it;
		it = start;
		while (it)
		{
			if (f(it->data))
			{
				return true;
			}
			it = it->next;
		}
		return false;
	}
}

template <typename T>
void DoubleLinkedList<T>::sort()
{
	if (!empty())
	{
		for (size_t i = 0; i < size; i++)
		{
			bool flag = false;
			DllElement<T>* it = start;
			DllElement<T>* nxt = it->next;
			while (nxt != NULL)
			{
				if (it->data > nxt->data)
				{
					swap(it->data, nxt->data);
					flag = true;
				}
				it = it->next;
				nxt = nxt->next;
			}
			if (!flag)
			{
				break;
			}
		}
	}
}
