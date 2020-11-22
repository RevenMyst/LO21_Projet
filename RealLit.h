#pragma once
#include "Litteral.h"

class LitReel : public Litteral
{
	int integer;
	unsigned int mantisse;
	LitType Type = REALLIT;
public:
	LitReel(int i, unsigned int m) : integer(i), mantisse(m) {}
	double getValue();
	std::string toString(int size);
};
