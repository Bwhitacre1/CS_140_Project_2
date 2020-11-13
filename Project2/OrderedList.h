#pragma once
#include "Node.h"


class OrderedList {
private:
	string payload;
	Node nextNode;

public:
	OrderedList();
	insert(Node);
	printOrderedList();
	clear();
	absorb(OrderedList);
};