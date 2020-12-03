#pragma once
#include <string>
#include "Operand.h"

class Operator : public Operand
{
private:
	bool verify();
protected:
	virtual void ope() = 0;
public:
	virtual std::string toString() const = 0;
	void exec();

};

class OpeDUP : public Operator {
	unsigned int arite = 1;
public:
	OpeDUP() = default;
	void ope() override;
	std::string toString() const { return "DUP"; }
	Operand* clone() { return new OpeDUP(*this); }
};

class OpeDROP : public Operator {
	unsigned int arite = 1;
public:
	OpeDROP() = default;
	void ope() override;
	std::string toString() const { return "DROP"; }
	Operand* clone() { return new OpeDROP(*this); }
};

class OpeCLEAR : public Operator {
	unsigned int arite = 1;
public:
	OpeCLEAR() = default;
	void ope() override;
	std::string toString() const { return "CLEAR"; }
	Operand* clone() { return new OpeCLEAR(*this); }
};

class OpeSWAP : public Operator {
	unsigned int arite = 2;
public:
	OpeSWAP() = default;
	void ope() override;
	std::string toString() const { return "SWAP"; }
	Operand* clone() { return new OpeSWAP(*this); }
};

class OpeSTO : public Operator {
	unsigned int arite = 2;
public:
	OpeSTO() = default;
	void ope() override;
	std::string toString() const { return "STO"; }
	Operand* clone() { return new OpeSTO(*this); }
};

class OpeFORGET : public Operator {
	unsigned int arite = 1;
public:
	OpeFORGET() = default;
	void ope() override;
	std::string toString() const { return "FORGET"; }
	Operand* clone() { return new OpeFORGET(*this); }
};

class OpeEVAL : public Operator {
	unsigned int arite = 1;
public:
	OpeEVAL() = default;
	void ope() override;
	std::string toString() const { return "EVAL"; }
	Operand* clone() { return new OpeEVAL(*this); }
};

class OpeAND : public Operator {
    unsigned int arite = 2;
public:
    OpeAND() = default;
    void ope() override;
    std::string toString() const { return "AND"; }
    Operand* clone() { return new OpeAND(*this); }
};

class OpeOR : public Operator {
    unsigned int arite = 2;
public:
    OpeOR() = default;
    void ope() override;
    std::string toString() const { return "OR"; }
    Operand* clone() { return new OpeOR(*this); }
};

class OpeEQUAL : public Operator {
	unsigned int arite = 2;
public:
	OpeEQUAL() = default;
	void ope() override;
	std::string toString() const { return "="; }
	Operand* clone() { return new OpeEQUAL(*this); }
};

class OpeLTE : public Operator {
	unsigned int arite = 2;
public:
	OpeLTE() = default;
	void ope() override;
	std::string toString() const { return "<="; }
	Operand* clone() { return new OpeLTE(*this); }
};

class OpeGTE : public Operator {
	unsigned int arite = 2;
public:
	OpeGTE() = default;
	void ope() override;
	std::string toString() const { return ">="; }
	Operand* clone() { return new OpeGTE(*this); }
};

class OpeGT : public Operator {
	unsigned int arite = 2;
public:
	OpeGT() = default;
	void ope() override;
	std::string toString() const { return ">"; }
	Operand* clone() { return new OpeGT(*this); }
};

class OpeLT : public Operator {
	unsigned int arite = 2;
public:
	OpeLT() = default;
	void ope() override;
	std::string toString() const { return "<"; }
	Operand* clone() { return new OpeLT(*this); }
};

class OpeDIF : public Operator {
	unsigned int arite = 2;
public:
	OpeDIF() = default;
	void ope() override;
	std::string toString() const { return "!="; }
	Operand* clone() { return new OpeDIF(*this); }
};

class OpeDIV : public Operator {
    unsigned int arite = 2;
public:
    OpeDIV() = default;
    void ope() override;
    std::string toString() const { return "DIV"; }
    Operand* clone() { return new OpeDIV(*this); }
};

class OpeMOD : public Operator {
    unsigned int arite = 2;
public:
    OpeMOD() = default;
    void ope() override;
    std::string toString() const { return "MOD"; }
    Operand* clone() { return new OpeMOD(*this); }
};
