#pragma once
#include "Operand.h"
const enum LitType { INTLIT, REALLIT, RATIONALLIT, EXPLIT, PROGLIT };

class Litteral : public Operand
{
protected:
	unsigned int arite = 0;
	LitType type;
public:
	virtual void accept(Visitor visitor);
	LitType getClass() const{ return type; }
	void exec();// a maj lors ajout pile
	virtual bool operator==(const Litteral& lit) const { return false; }
	virtual bool operator>=(const Litteral& lit) const { return false; }
	virtual bool operator<=(const Litteral& lit) const { return false; }
	virtual bool operator>(const Litteral& lit) const { return false; }
	virtual bool operator<(const Litteral& lit) const { return false; }

};


