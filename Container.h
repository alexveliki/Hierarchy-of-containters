#pragma once

#include <string>
#include <fstream>
#include <typeinfo>
using namespace std;

using Condition = bool (*)(int const&);


template <typename T>
class Container{

public:
	virtual void add(T const&) = 0;          // 2.1
	virtual void remove() = 0;               // 2.2
	virtual bool empty() = 0;
	virtual T getElement() = 0;
	virtual size_t getSize() = 0;
	virtual string getType() = 0;
	virtual void print() = 0;
	virtual void printToFile(ofstream&) = 0;
	virtual bool member(T const&) = 0;
	virtual bool checkCond(Condition) = 0;   // 5
	virtual void sort() = 0;
	string getElementType()
	{
		return typeid(T).name();
	}
};