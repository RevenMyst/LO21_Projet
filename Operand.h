#pragma once
#include <string>
class Operand
{
protected:
	unsigned int arite;
public:
	virtual std::string toString() const;
	virtual void exec();
};


