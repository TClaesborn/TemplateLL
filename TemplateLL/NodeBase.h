#pragma once
#include <memory>
class NodeBase
{
public:
	std::shared_ptr<NodeBase> next;
	
	virtual ~NodeBase() = default; // default constructor s�ger till anv�ndaren att ingen annan cleanup �r n�dv�ndig.
	virtual void print() const = 0; // Virtuell funktion g�r klassen abstrakt s� att den ej kan instantieras.
	// Virtuella funktioner M�STE implementeras i underklasser.
};

