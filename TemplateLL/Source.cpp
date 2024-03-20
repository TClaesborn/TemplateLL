#include "List.h"

class Game
{
public:
	
};

std::ostream& operator<<(std::ostream& os, const Game& obj) {
	// Operator overload för std::cout så att 'Game' kan skrivas ut, tomt fält nu då implementation saknas.
	return os;
}

int main()
{
	List list;
	Game game;
	list.addElement("Hello World");
	list.addElement(3);
	list.addElement(3.2f);
	list.addElement(game);
	list.addElement(3.21);
	list.insertAt(2, "New element.");
	list.printAll();
}