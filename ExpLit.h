#pragma once
#include "Litteral.h"
class ExpLit : public Litteral
{
	std::string name;
	LitType type = EXPLIT;
public:
	ExpLit(std::string str) :name(str){}
	std::string toString() const { return name; }
	void accept(Visitor& visitor) const override { visitor.visitExpLit(*this); }
	bool operator==(const Litteral& lit) const override { return toString() == lit.toString(); }
	bool operator!=(const Litteral& lit) const override { return toString() != lit.toString(); }

};

