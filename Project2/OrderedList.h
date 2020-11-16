//
//  OrderedList.h
//  Project2
//
//  Created by Beatriz Verin on 11/12/20.
//  Copyright © 2020 Beatriz Verin and Brian Whitacre. All rights reserved.
//
#include "Node.h"
#pragma once
class OrderedList
{
private:
    Node* fNode; // a pointer to the first node in the OrderedList

public:
    OrderedList(); // empty constructor
    ~OrderedList();
    void insert(Node node);
    Node remove(Node node);
    Node removeFront();
    void clear();
    void absorb(OrderedList& absorbNode);
    void printOrderedList();
};
