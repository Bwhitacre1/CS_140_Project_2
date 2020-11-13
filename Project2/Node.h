#pragma once

#include <string>

// forward declaration of OrderedList
class OrderedList;

class Node
{
    friend class OrderedList;
public:
    explicit Node(const std::string& p);
private:
    std::string payload;
    Node* nextNode{ nullptr };
};
