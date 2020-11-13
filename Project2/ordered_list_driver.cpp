#include <iostream>
#include "Node.h"
#include "OrderedList.h"

using namespace std;

int main()
{
	cout << "***   Ordered List Driver   ***" << endl << endl;

	OrderedList list1;
	OrderedList list2;
	OrderedList list3;

	Node a1("alpha");
	Node b1("bravo");
	Node c1("charlie");

	Node a2("apple");
	Node b2("banana");
	Node c2("cranberry");

	cout << "Testing some different insertion orders..." << endl << endl;

	list1.insert(a1);
	list1.insert(b1);
	list1.insert(c1);
	list1.insert(a2);
	list1.insert(b2);
	list1.insert(c2);

	cout << "List1:" << endl;
	list1.printOrderedList();
	list1.clear();

	list1.insert(a1);
	list1.insert(c2);
	list1.insert(b2);
	list1.insert(c1);
	list1.insert(b1);
	list1.insert(a2);

	cout << "List1:" << endl;
	list1.printOrderedList();
	list1.clear();

	list1.insert(b1);
	list1.insert(a2);
	list1.insert(b2);
	list1.insert(a1);
	list1.insert(c2);
	list1.insert(c1);

	cout << "List1:" << endl;
	list1.printOrderedList();
	list1.clear();

	Node m1("mike");
	Node n1("november");
	Node o1("oscar");

	Node x1("x-ray");
	Node y1("yankee");
	Node z1("zulu");

	cout << "Testing absorb method..." << endl << endl;

	list1.insert(a1);
	list1.insert(n1);
	list1.insert(z1);

	list2.insert(x1);
	list2.insert(c1);
	list2.insert(m1);
		
	list3.insert(o1);
	list3.insert(y1);
	list3.insert(b1);

	cout << "list1:" << endl;
	list1.printOrderedList();
	cout << "list2:" << endl;
	list2.printOrderedList();
	cout << "list3:" << endl;
	list3.printOrderedList();

	cout << "list1 absorbing list2..." << endl << endl;
	list1.absorb(list2);

	cout << "list1:" << endl;
	list1.printOrderedList();
	cout << "list2:" << endl;
	list2.printOrderedList();
	cout << "list3:" << endl;
	list3.printOrderedList();

	cout << "list1 absorbing list3..." << endl << endl;
	list1.absorb(list3);

	cout << "list1:" << endl;
	list1.printOrderedList();
	cout << "list2:" << endl;
	list2.printOrderedList();
	cout << "list3:" << endl;
	list3.printOrderedList();

	list1.clear();

	cout << "Testing insertion of duplicates..." << endl << endl;
	Node a3("alpha");
	Node a4("alpha");
	Node q1("quebec");	//let's throw a new one in there too
	Node q2("quebec");
	Node z2("zulu");
	Node z3("zulu");

	list1.insert(a3);	
	list1.insert(q1);
	list1.insert(z1);
	list1.insert(a4);
	list1.insert(q2);
	list1.insert(z2);

	cout << "list1:" << endl;
	list1.printOrderedList();
}

/* 

***   Ordered List Driver   ***

Testing some different insertion orders...

List1:
alpha apple banana bravo charlie cranberry

List1:
alpha apple banana bravo charlie cranberry

List1:
alpha apple banana bravo charlie cranberry

Testing absorb method...

list1:
alpha november zulu

list2:
charlie mike x-ray

list3:
bravo oscar yankee

list1 absorbing list2...

list1:
alpha charlie mike november x-ray zulu

list2:


list3:
bravo oscar yankee

list1 absorbing list3...

list1:
alpha bravo charlie mike november oscar x-ray yankee zulu

list2:


list3:


Testing insertion of duplicates...

list1:
alpha quebec zulu

Destructor invoked...
All nodes destroyed.

Destructor invoked...
All nodes destroyed.

Destructor invoked...
Destroying alpha
Destroying quebec
Destroying zulu
All nodes destroyed.

 */