#pragma once
#include <memory>
#include <iostream>
#include "Node.h"

class List
{
	std::shared_ptr<NodeBase> head;
public:
    List() = default; // default constructor informerar anv�ndaren (andra programmerare) att denna constructor inte beh�ver n�gonting mer.

	template <typename T>
    NodeBase& addElement(T data) 
    {
        // Hitta slutet p� listan och l�gg till elementet d�r.
        auto newNode = std::make_shared<Node<T>>(data);
        if (!head) {
            head = newNode;
        }
        else {
            auto current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        return *newNode;
    }

    template <typename T>
    void insertAt(int position, T data) {
        auto newNode = std::make_shared<Node<T>>(data);
        if (position == 0) { // L�gg till f�rst om pos = 0
            newNode->next = head;
            head = newNode;
            return;
        }

        auto current = head;
        int currentIndex = 0;
        // Iterera genom listan f�r att hitta positionen att l�gga till elementet p�
        while (current != nullptr && currentIndex < position - 1) {
            current = current->next;
            currentIndex++;
        }

        if (current != nullptr) {
            // L�gg till noden vid vald position
            newNode->next = current->next;
            current->next = newNode;
        }
        else {
            // Om vald position �r 'out of range', g�r ingenting.
            // Alternativet �r att l�gga till i slutet av listan f�r att underl�tta f�r anv�ndaren.
            std::cout << "Position out of range. No insertion made." << std::endl;
        }
    }

    void printAll()
    {
        // Iterera genom listan och skriv ut varje element
        auto current = head;
        while (current)
        {
            current->print();
            current = current->next;
        }
    }

};

