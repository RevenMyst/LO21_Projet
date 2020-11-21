#pragma once

#include "Litteral.h"

class LitInt : public Litteral
{
	int value;
public:
	int getValue() { return value; }
};
