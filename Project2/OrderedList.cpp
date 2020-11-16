//
//  OrderList.cpp
//  Project2
//
//  Created by Beatriz Verin on 11/15/20.
//  Copyright © 2020 Beatriz Verin and Brian Whitacre. All rights reserved.
//
#include <stdio.h>
#include "OrderedList.h"
#include <iostream>

OrderedList::OrderedList() :
    fNode(NULL) {}

void OrderedList::insert(Node node)
{
    if (fNode == NULL || fNode->payload > node.payload) // if the list is null or fNode's payload > node's payload then insert as the first node
    {
        Node* temp = new Node(node.payload);
        temp->nextNode = fNode;
        fNode = temp;
    }
    else
    {
        Node* current = fNode;
        Node* previous = NULL;
        //loops over the list to find the position of insertion
        while (current != NULL)
        {
            if (current->payload == node.payload || current->payload > node.payload)
                break;

            previous = current;
            current = current->nextNode;
        }
        if (current == NULL || current->payload != node.payload)
        {
            Node* temp = new Node(node.payload);
            previous->nextNode = temp;
            temp->nextNode = current;
        }
    }
}

Node OrderedList::remove(Node node)
{
    Node* current = fNode;
    Node* previous = NULL;

    while (current != NULL)
    {
        if (current->payload == node.payload || current->payload > node.payload)
        {
            break;
            previous = current;
            current = current->nextNode;
        }
        if (current == NULL)
        {
            if (current->payload == node.payload)
            {
                if (previous == NULL) // first node is payload
                    return removeFront();
            }
            else
            {
                previous->nextNode = current->nextNode;
                Node temp(current->payload); //creatinga temporary node to return
                current->nextNode = NULL;
                delete current;
                current = NULL;

                return temp;
            }

        }
    }

}

    //destructor that deletes all of the nodes
    OrderedList :: ~OrderedList()
    {
        std::cout << " OrderedList Destructor has been called" << std::endl;
        Node* node;
        //loop over the list, deleting the nodes in the list
        while (fNode != NULL)
        {
            node = fNode;
            fNode = fNode->nextNode;
            std::cout << "Deleting" << node->payload << std::endl;
            node->nextNode = NULL;
            delete node;
            node = NULL;
        }
    }


Node OrderedList::removeFront() {
    Node savedValue = *fNode;
    fNode = fNode->nextNode;
    return savedValue;
}

void OrderedList::clear() {
    Node* node;
    while (fNode != NULL) {
        node = fNode;
        fNode = fNode->nextNode;
        node->nextNode = NULL;
        delete node;
        node = NULL;

    }
    



}

void OrderedList::absorb(OrderedList& absorbNode) {
    Node* currentNode = absorbNode.fNode;
    Node* previousNode = NULL;

    while (currentNode != NULL) {
        insert(*currentNode);
        previousNode = currentNode;
        //absorbNode.remove(*currentNode);
        currentNode = previousNode->nextNode;
    }

    //delete currentNode;
}

void OrderedList::printOrderedList() {
    Node* current = fNode;
    Node* previous = NULL;

    while (current != NULL)
    {
        std::cout << current->payload << " ";
        previous = current;
        current = current->nextNode;
    }
    std::cout << "\n";

    //delete current;
    //delete previous;
}
