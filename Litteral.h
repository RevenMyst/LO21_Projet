#ifndef LITTERAL_H
#define LITTERAL_H

#pragma once
#include "Operand.h"
const enum LitType { INTLIT, REALLIT, RATIONALLIT, EXPLIT, PROGLIT };

class Litteral : public Operand
{
protected:
	unsigned int arite = 0;
	LitType Type;
public:
	void accept(Visitor visitor);
	LitType getClass() { return Type; }
	void exec();
};

#endif
