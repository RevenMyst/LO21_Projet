#pragma once
#include "Operand.h"
const enum LitType { INTLIT, REALLIT, RATIONALLIT, EXPLIT, PROGLIT };

class Litteral : public Operand
{
protected:
	unsigned int arite = 0;
	LitType type;
public:
	void accept(Visitor visitor);
	LitType getClass() { return type; }
	void exec();
};


