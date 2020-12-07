#pragma once
#include <list>

class Litteral;

class Pile
{
	std::list<Litteral*> litterals;
	
public:

	Pile() = default;
	Pile(Pile& p);
	void push(Litteral* lit);
	Litteral* pull();
	unsigned int size() const { return litterals.size(); }
	std::list<Litteral*>& getLitterals() { return litterals; }
	~Pile();
};

