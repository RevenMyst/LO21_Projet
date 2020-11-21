#pragma once

#include "Litteral.h"

class LitInt : public Litteral
{
	int value;
	LitType Type = INTLIT;
public:
	int getValue() { return value; }
};
