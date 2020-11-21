#pragma once
#include "Litteral.h"

class LitReel : public Litteral
{
	int integer;
	unsigned int mantisse;
public:
	double getValue();
};
