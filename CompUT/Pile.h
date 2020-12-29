//////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> Stock les Litterales </summary>
///
/// <classes> Pile </classes>
///
///////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <list>

class Litteral;

class Pile
{
	std::list<Litteral*> litterals;
    unsigned int elementsAAfficher = 10;

public:

	Pile() = default;
	Pile(Pile& p);
    //ajout/empilement
	void push(Litteral* lit);
    //retrait/depilement
	Litteral* pull();
    size_t size() const { return litterals.size(); }
    // retourne tous les element de la pile
	std::list<Litteral*>& getLitterals() { return litterals; }
    // retourne reference pour autoriser modification
    unsigned int& toShow() {return elementsAAfficher;}
	~Pile();
};
