#pragma once
#include "Pile.h"
#include <string>
class Computer
{
private:
	Pile* pile;
	Computer() :pile(new Pile()){}
	Computer(const Computer& c);
	Computer& operator=(const Computer& c) = default;
	~Computer() { delete pile; }
public:
	static Computer& getInstance() {
		static Computer instance;
		return instance;
	}
	Pile* getPile() { return pile; }
};


