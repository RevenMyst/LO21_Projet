#pragma once

#include "Litteral.h"


class LitInt : public LitteralNumerique

{
	int value;
	LitType Type = INTLIT;
public:

	LitInt(int v) : value(v){}
	int getValue() const { return value; }
	std::string toString(int size) const{
		std::string res = std::to_string(getValue());
		return(res);
	}

};
