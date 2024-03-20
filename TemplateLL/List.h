#pragma once
#include <memory>
#include <iostream>
#include "Node.h"

class List
{
	std::shared_ptr<NodeBase> head;
public:
    List() = default; // default constructor informerar användaren (andra programmerare) att denna constructor inte behöver någonting mer.

	template <typename T>
    NodeBase& addElement(T data) 
    {
        // Hitta slutet på listan och lägg till elementet där.
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
        if (position == 0) { // Lägg till först om pos = 0
            newNode->next = head;
            head = newNode;
            return;
        }

        auto current = head;
        int currentIndex = 0;
        // Iterera genom listan för att hitta positionen att lägga till elementet på
        while (current != nullptr && currentIndex < position - 1) {
            current = current->next;
            currentIndex++;
        }

        if (current != nullptr) {
            // Lägg till noden vid vald position
            newNode->next = current->next;
            current->next = newNode;
        }
        else {
            // Om vald position är 'out of range', gör ingenting.
            // Alternativet är att lägga till i slutet av listan för att underlätta för användaren.
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

