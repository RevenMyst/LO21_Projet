#pragma once

#include "Litteral.h"

class LitInt : public Litteral
{
	int value;
	LitType Type = INTLIT;
public:
	LitInt(int v) : value(v){}
	int getValue() { return value; }
	std::string toString(int size) {
		std::string res = std::to_string(value);
		return(res);
	}
};
