#include "Pile.h"
#include <iostream>
#include "ComputerException.h"
#include "Litteral.h"

Pile::Pile(Pile& p)
{
	for (Litteral* l : p.litterals) {
		
        litterals.push_front(dynamic_cast<Litteral*>(l->clone()));
	}
}

void Pile::push(Litteral* lit)
{
    litterals.push_front(lit);
}

Litteral* Pile::pull()
{
	if (size() > 0) {

		Litteral* lit = nullptr;
        lit = litterals.front();
        litterals.pop_front();
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
