#pragma once
#include <string>
#include "Operand.h"
class Operator : public Operand
{
private:
	bool verify();
protected:
	std::string symbole;
	virtual void ope() = 0;
public:
	std::string toString() const { return symbole; }
	void exec();

};

class OpeDUP : public Operator {
	unsigned int arite = 1;
	std::string symbole = "DUP";
public:
	OpeDUP() = default;
	void ope() override;
	Operand* clone() { return new OpeDUP(*this); }
};

class OpeDROP : public Operator {
	unsigned int arite = 1;
	std::string symbole = "DROP";
public:
	OpeDROP() = default;
	void ope() override;
	Operand* clone() { return new OpeDROP(*this); }
};

class OpeCLEAR : public Operator {
	unsigned int arite = 1;
	std::string symbole = "CLEAR";
public:
	OpeCLEAR() = default;
	void ope() override;
	Operand* clone() { return new OpeCLEAR(*this); }
};

class OpeSWAP : public Operator {
	unsigned int arite = 2;
	std::string symbole = "SWAP";
public:
	OpeSWAP() = default;
	void ope() override;
	Operand* clone() { return new OpeSWAP(*this); }
};
