#pragma once
#include <vector>

class Litteral;

class Pile
{
	std::vector<Litteral*> litterals;
	
public:

	Pile() = default;
	void push(Litteral* lit);
	Litteral* pull();
	unsigned int size() const { return litterals.size(); }
	~Pile();
};

