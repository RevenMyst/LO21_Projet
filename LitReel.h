#pragma once
#include "Litteral.h"

class LitReel : public Litteral
{
	int integer;
	unsigned int mantisse;
	LitType Type = REALLIT;
public:
	double getValue();
};
