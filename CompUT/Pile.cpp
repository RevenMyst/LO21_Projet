#include "Pile.h"
#include <iostream>
#include "ComputerException.h"
#include "Litteral.h"

Pile::Pile(Pile& p)
{
    //lors copy il faut cloner les element de la pile
	for (Litteral* l : p.litterals) {

        litterals.push_back(dynamic_cast<Litteral*>(l->clone()));
	}
}

void Pile::push(Litteral* lit)
{
    litterals.push_front(lit);
}

Litteral* Pile::pull()
{
	if (size() > 0) {
    //on recup le premeier element de la pile
		Litteral* lit = nullptr;
        lit = litterals.front();
    //on l'enleve de la pile
        litterals.pop_front();
    // on retourne
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
