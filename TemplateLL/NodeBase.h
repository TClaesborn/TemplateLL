#pragma once
#include <memory>
class NodeBase
{
public:
	std::shared_ptr<NodeBase> next;
	
	virtual ~NodeBase() = default; // default constructor säger till användaren att ingen annan cleanup är nödvändig.
	virtual void print() const = 0; // Virtuell funktion gör klassen abstrakt så att den ej kan instantieras.
	// Virtuella funktioner MÅSTE implementeras i underklasser.
};

