#pragma once

#include "Container.h"
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class Queue : public Container<T>
{
	Node<T>* front;
	size_t size;

	void copy(const Queue<T>&);
	void clear();

public:
	Queue();
	~Queue();
	Queue(const Queue&);
	Queue& operator=(const Queue&);

	void add(T const&); 
	void remove();      
	T getElement();	

	size_t getSize();
	string getType();

	void print();
	void printToFile(ofstream&);
	bool empty();
	void sort();

	bool member(T const&);
	bool checkCond(Condition);

};

template <typename T>
Queue<T>::Queue()
{
	front = NULL;
	size = 0;
}

template <typename T>
Queue<T>::Queue(const Queue& other)
{
	copy(other);
}

template <typename T>
void Queue<T>::copy(const Queue<T>& other)
{
	Node<T>* it = new Node<T>;
	it = other.front;
	while (it)
	{
		add(it->data);
		it = it->next;
	}
}

template <typename T>
void Queue<T>::clear()
{
	while (!empty())
	{
		remove();
	}
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
	if (this != other)
	{
		clear();
		copy(other);
	}
	return *this;
}

template <typename T>
Queue<T>::~Queue()
{
	clear();
}

template <typename T>
void Queue<T>::add(T const& el) 
{
	Node<T>* temp = new Node<T>;
	temp->data = el;
	temp->next = NULL;

	if (empty())
	{
		front = temp;
	}
	else
	{
		Node<T>* it = new Node<T>;
		it = front;
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
void Queue<T>::remove()   
{
	if (!empty())
	{
		Node<T>* temp = front->next;
		delete front;
		front = temp;
		size--;
	}

}


template <typename T>
bool Queue<T>::empty()
{
	return front == NULL;
}

template <typename T>
T Queue<T>::getElement()
{
	return front->data;
}

template<typename T>
size_t Queue<T>::getSize()
{
	return size;
}

template<typename T>
string Queue<T>::getType()
{
	return "Q";
}

template <typename T>
void Queue<T>::print()
{
	if (empty())
	{
		cout << "Empty queue" << endl;
	}
	else
	{
		Node<T>* it;
		it = front;
		cout << "Queue: ";
		while (it)
		{
			cout << it->data << " ";
			it = it->next;
		}
		cout << endl;
	}
}

template <typename T>
void Queue<T>::printToFile(ofstream& fout)
{
	if(!empty())
	{
		Node<T>* it = front;
		fout << "Q ";
		//fout << this->getElementType() << " ";

		while (it)
		{
			fout << it->data << " ";
			it = it->next;
		}
		fout << endl;
	}
}

template <typename T>
bool Queue<T>::member(T const& x)
{
	Node<T>* it;
	it = front;
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
bool Queue<T>::checkCond(Condition f)
{
	if (empty())
	{
		return false;
	}
	else
	{
		Node<T>* it;
		it = front;
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
void Queue<T>::sort()
{
	if (!empty())
	{
		for (size_t i = 0; i < size; i++)
		{
			bool flag = false;
			Node<T>* it = front;
			Node<T>* nxt = it->next;
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