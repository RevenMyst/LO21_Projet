#pragma once
#include <string>
#include "Computer.h"
class Operand
{
protected:
	unsigned int arite = 0;
public:

	virtual std::string toString() const= 0;
	virtual void exec() = 0;
	virtual ~Operand()= default;
	virtual Operand* clone() = 0;

};


