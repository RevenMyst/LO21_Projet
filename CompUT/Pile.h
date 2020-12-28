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
	void push(Litteral* lit);
	Litteral* pull();
    size_t size() const { return litterals.size(); }
	std::list<Litteral*>& getLitterals() { return litterals; }
    unsigned int& toShow() {return elementsAAfficher;}
	~Pile();
};
