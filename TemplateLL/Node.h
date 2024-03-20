#pragma once
#include "NodeBase.h"
#include <iostream>
template <typename T>
class Node : public NodeBase {
public:
    T data;

    Node(T data) : data(data) {}

    void print() const override // Implementering av virtuell funktion, krav från parent class.
    {
        std::cout << data << std::endl;
    }
};
