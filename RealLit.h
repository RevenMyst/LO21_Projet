#pragma once
#include "Litteral.h"

class LitReel : public LitteralNumerique
{
	int integer;
	unsigned int mantisse;
	LitType Type = REALLIT;
public:
	LitReel(int i, unsigned int m) : integer(i), mantisse(m) {}
	int getInt() const { return integer; }
	unsigned int getMant() const { return mantisse; }
	double getValueR() const;
	int getValue() const;
	std::string toString(int size) const;
};
