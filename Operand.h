#ifndef OPERAND_H
#define OPERAND_H

#pragma once
#include <string>
class Operand
{
protected:
	unsigned int arite;
public:
	virtual std::string toString(int size)= 0;
	virtual void exec() = 0;
};

#endif
