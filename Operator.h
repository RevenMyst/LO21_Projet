#pragma once
#include "Operand.h"

class Operator : public Operand
{
protected:
	std::string Symbole;
private:
	bool verify();
public:
	std::string toString();
	void exec();
protected:
	void ope();
};
