#pragma once
#include "Container.h"
#include "Node.h"
#include <iostream>

using namespace std;

using Condition = bool (*)(int const&);

template <typename T>
class Stack : public Container<T>
{
	Node<T>* top;
	size_t size;

	void copy(Stack<T>&);
	void clear();

public:
	Stack();
	~Stack();
	Stack(Stack&);
	Stack& operator=(Stack&);

	void add(T const&);
	void remove();          
	T getElement();     

	size_t getSize();
	string getType();

	bool empty();
	void print();
	void printToFile(ofstream&);

	bool member(T const&);
	bool checkCond(Condition);
	void sort();
};


template <typename T>
Stack<T>::Stack()
{
	top = NULL;
	size = 0;
}

template <typename T>
void Stack<T>::copy(Stack<T>& other)
{
	Node<T>* it = new Node<T>;
	it = other.top;


	Stack<T>* temp = new Stack<T>;
	while (it)
	{
		temp->add(it->data);
		it = it ->next;
	}
	while (!temp->empty())
	{
		add(temp->getElement());
		temp->remove();
	}



	/*while (it)
	{
		add(it->data);
		it = it->next;
	}*/
}

template <typename T>
void Stack<T>::clear()
{
	while (!empty())
	{
		remove();
	}
}


template <typename T>
Stack<T>::Stack(Stack<T>& other)
{
	copy(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack& other)
{
	if (this != other)
	{
		clear();
		copy(other);
	}
	return *this;
}


template <typename T>
Stack<T>::~Stack()
{
	clear();
}

template <typename T>
void Stack<T>::add(const T& _data)
{
	Node<T>* temp = new Node<T>;
	temp->data = _data;
	temp->next = top;
	top = temp;
	size++;
}

template <typename T>
void Stack<T>::remove()
{
	if (!empty())
	{
		Node<T>* temp = top;
		top = temp->next;
		delete temp;
		size--;
	}
}


template <typename T>
T Stack<T>::getElement()
{
	return top->data;
}

template <typename T>
bool Stack<T>::empty()
{
	return top == NULL;
}

template<typename T>
size_t Stack<T>::getSize()
{
	return size;
}

template<typename T>
string Stack<T>::getType()
{
	return "S";
}

template <typename T>
void Stack<T>::print()
{
	if (empty())
	{
		cout << "Empty stack" << endl;
	}
	else
	{
		cout << "Stack: ";

		Node<T>* it = top;
		while (it != NULL)
		{
			cout << it->data << " ";
			it = it->next;
		}
		cout << endl;
	}
}
template <typename T>
void Stack<T>::printToFile(ofstream& fout)
{
	if (!empty())
	{
		fout << "S ";
		//fout << this->getElementType() << " ";

		Node<T>* it = top;
		while (it != NULL)
		{
			fout << it->data << " ";
			it = it->next;
		}
		fout << endl;
	}
}

template <typename T>
bool Stack<T>::member(const T& x)
{
	Node<T>* it;
	it = top;
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
bool Stack<T>::checkCond(Condition f)
{
	if (empty())
	{
		return false;
	}
	else
	{
		Node<T>* it;
		it = top;
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
void Stack<T>::sort()
{
	if (!empty())
	{
		for (size_t i = 0; i < size; i++)
		{
			bool flag = false;
			Node<T>* it = top;
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



