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
	LitType getClass() const { return Type; }
	void exec();
};

class LitteralNumerique : public Litteral
{
public:
	virtual int getValue() const = 0;
};

bool operator==(const Litteral& Lit1, const Litteral& Lit2) const;
bool operator!=(const Litteral& Lit1, const Litteral& Lit2) const;
bool operator>=(const Litteral& Lit1, const Litteral& Lit2) const;
bool operator<=(const Litteral& Lit1, const Litteral& Lit2) const;
bool operator>(const Litteral& Lit1, const Litteral& Lit2) const;
bool operator<(const Litteral& Lit1, const Litteral& Lit2) const;
