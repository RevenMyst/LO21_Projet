#pragma once
#include <string>
class Operand
{
protected:
	unsigned int arite;
public:
	virtual std::string toString(int size);
	virtual void exec();
};


