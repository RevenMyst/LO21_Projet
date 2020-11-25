#include "Pile.h"
#include "ComputerException.h"
#include <iostream>

void Pile::push(Litteral* lit)
{
	litterals.push_back(lit);
}

Litteral* Pile::pull()
{
	if (size() > 0) {

		Litteral* lit = nullptr;
		lit = litterals.back();
		litterals.pop_back();
		return lit;
	}
	else {
		throw ComputerException("Erreur : Il n'y a plus d'element dans la pile");
	}

}




Pile::~Pile()
{
	for (Litteral* l : litterals) {
		delete l;
	}
}
