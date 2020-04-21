#include<iostream>
#include "Container.h"
#include "Stack.cpp"
#include "Queue.cpp"
#include "DoubleLinkedList.cpp"
#include "HeterogeneousLinkedList.cpp"
using namespace std;


bool isEven(int const& x)
{
	return x % 2 == 0;
}

int main()
{
	ifstream fin("in.txt");
	HeterogeneousLinkedList<int> h(fin, 7);

	ofstream checkFormating("outOriginal.txt");
	h.printToFile(checkFormating);

	ofstream fout("out.txt");
	
	h.printAll();
	cout << endl;
	h.printAll();
	cout << endl;
	//h.sortAll();
	h.filter(isEven);
	h.printAll();
	cout << " --------- \n";
	h.printToFile(fout);
	h.printAll();
	h.sortAll();
	cout << "------------\n";
	h.printAll();
	h.addToSmallest(7);
	cout << "------------\n";
	h.printAll();
	cout << h.checkContain(7) << endl;
	cout << h.checkContain(21) << endl;
	cout << h.checkContain(3) << endl;


	Container<int>* asd = h.findElement(47);
	if (asd == NULL) cout << -1 << endl;
	else asd->print();
	asd = h.findElement(7);
	if (asd == NULL) cout << -1 << endl;
	else asd->print();


	h.iterateAllSorted();
	asd = h.findElement(7);
	if (asd == NULL) cout << -1 << endl;
	else asd->print();

	h.printAll();
	ofstream fout2("out2.txt");
	h.printToFile(fout2);
	/*Stack<int> s;
	s.add(1);
	cout << s.checkCond(isEven) << endl;
	s.add(2);
	cout << s.checkCond(isEven) << endl;
	cout << "-------------\n";
	s.add(6);
	s.add(4);
	cout << s.getElement() << endl;
	s.remove();
	cout << s.getElement() << endl;
	s.add(5);
	s.print();

	Queue<int> q;
	q.add(1);
	q.add(2);
	q.add(3);
	q.print();
	cout << q.getElement() << endl;
	q.remove();
	cout << q.getElement() << endl;
	cout << q.checkCond(isEven) << endl;
	q.remove();
	cout << q.checkCond(isEven) << endl;
	
	DoubleLinkedList<int> l;
	l.add(1);
	l.add(2);
	l.add(3);
	l.print();
	cout << l.getElement() << endl;
	l.remove();
	cout << l.getElement() << endl;
	cout << l.checkCond(isEven) << endl;
	l.remove();
	cout << l.checkCond(isEven) << endl;
	
	cout << "END\n";*/


	/*Stack<int> s;
	s.add(1);
	s.add(2);
	Stack<int> s2(s);
	s2.print();*/
	//cout << s.top() << endl;
	//cout << 1 << endl;
	//Container<int>* c[4];
	//c[0] = new Queue<int>;

	/*Queue<int> s;
	//c[0]->add(1);
	s.add(2);
	s.add(3);
	s.add(4);
	s.add(5);
	s.add(6);
	cout << "------------\n";
	cout << s.member(3) << endl;
	cout << s.member(1) << endl;
	cout << s.member(6) << endl;
	cout << s.member(7) << endl;
	cout << s.member(2) << endl;
	cout << "------------\n";
	//cout << s.empty() << endl;
	//cout << c[0]->getElement() << endl;
	//s.pop();
	//cout << s.empty() << endl;
	cout << (int) s.getElement() << endl;s.remove();
	//cout << s.empty() << endl;
	cout << (int)s.getElement() << endl;s.remove();
	//cout << s.empty() << endl;
	cout << (int)s.getElement() << endl;s.remove();
	//cout << s.empty() << endl;
	cout << (int)s.getElement() << endl;s.remove();
	//cout << s.empty() << endl;
	cout << (int)s.getElement() << endl;s.remove();
	//cout << s.empty() << endl;
	cout << (int)s.getElement() << endl;s.remove();
	//cout << s.empty() << endl;
	cout << (int)s.getElement() << endl;s.remove();
	//cout << s.empty() << endl;
	cout << (int)s.getElement() << endl;s.remove();
	//cout << s.empty() << endl;
	cout << (int)s.getElement() << endl;
	//cout << s.empty() << endl;
	s.remove();*/
	return 0;
}