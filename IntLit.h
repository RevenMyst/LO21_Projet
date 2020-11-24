#pragma once

#include "Litteral.h"


class LitInt : public LitteralNumerique

{
	int value;
	LitType Type = INTLIT;
public:

	LitInt(int v) : value(v){}
	double getValue() const { return value; }
	int getInt() const {return value} //retourne de valeur en int (pas de 1.0)
	std::string toString(int size) const{
		std::string res = std::to_string(getInt());
		return(res);
	}

};
