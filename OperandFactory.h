#pragma once
#include <string>
class Operand;
class OperandFactory
{
	Operand* createOperand(std::string str);
};

