#pragma once
#include <string>
#include "Operand.h"
#include "Visitor.h"

class Operator : public Operand
{
private:
	unsigned int arite;
	bool verify();
protected:
	virtual void ope() = 0;
public:
	Operator(unsigned int a):arite(a){}
	virtual std::string toString() const = 0;
	void exec();

};

class OpeDUP : public Operator {
public:
	OpeDUP() : Operator(1){}
	void ope() override;
	std::string toString() const { return "DUP"; }
	Operand* clone() { return new OpeDUP(*this); }
};

class OpeDROP : public Operator {
public:
	OpeDROP() : Operator(1) {}
	void ope() override;
	std::string toString() const { return "DROP"; }
	Operand* clone() { return new OpeDROP(*this); }
};

class OpeCLEAR : public Operator {
public:
	OpeCLEAR() : Operator(1) {}
	void ope() override;
	std::string toString() const { return "CLEAR"; }
	Operand* clone() { return new OpeCLEAR(*this); }
};

class OpeSWAP : public Operator {
public:
	OpeSWAP() : Operator(2) {}
	void ope() override;
	std::string toString() const { return "SWAP"; }
	Operand* clone() { return new OpeSWAP(*this); }
};

class OpeSTO : public Operator {
public:
	OpeSTO() : Operator(2) {}
	void ope() override;
	std::string toString() const { return "STO"; }
	Operand* clone() { return new OpeSTO(*this); }
};

class OpeFORGET : public Operator, public Visitor {
public:
	OpeFORGET() : Operator(2) {}
	void ope() override;
	void visitExpLit(ExpLit* l1) override;
	std::string toString() const { return "FORGET"; }
	Operand* clone() { return new OpeFORGET(*this); }
};

class OpeEVAL : public Operator, public Visitor {
public:
	OpeEVAL() : Operator(1) {}
	void ope() override;
	void visitExpLit(ExpLit* l1) override;
	void visitProgLit(ProgLit* l1) override;
	std::string toString() const { return "EVAL"; }
	Operand* clone() { return new OpeEVAL(*this); }
};

class OpeAND : public Operator {
public:
    OpeAND() : Operator(2) {}
    void ope() override;
    std::string toString() const { return "AND"; }
    Operand* clone() { return new OpeAND(*this); }
};

class OpeOR : public Operator {
public:
    OpeOR() : Operator(2) {}
    void ope() override;
    std::string toString() const { return "OR"; }
    Operand* clone() { return new OpeOR(*this); }
};

class OpeEQUAL : public Operator {
public:
	OpeEQUAL() : Operator(2) {}
	void ope() override;
	std::string toString() const { return "="; }
	Operand* clone() { return new OpeEQUAL(*this); }
};

class OpeLTE : public Operator {
public:
	OpeLTE() : Operator(2) {}
	void ope() override;
	std::string toString() const { return "<="; }
	Operand* clone() { return new OpeLTE(*this); }
};

class OpeGTE : public Operator {
public:
	OpeGTE() : Operator(2) {}
	void ope() override;
	std::string toString() const { return ">="; }
	Operand* clone() { return new OpeGTE(*this); }
};

class OpeGT : public Operator {
public:
	OpeGT() : Operator(2) {}
	void ope() override;
	std::string toString() const { return ">"; }
	Operand* clone() { return new OpeGT(*this); }
};

class OpeLT : public Operator {
public:
	OpeLT() : Operator(2) {}
	void ope() override;
	std::string toString() const { return "<"; }
	Operand* clone() { return new OpeLT(*this); }
};

class OpeDIF : public Operator {
public:
	OpeDIF() : Operator(2) {}
	void ope() override;
	std::string toString() const { return "!="; }
	Operand* clone() { return new OpeDIF(*this); }
};

class OpeDIV : public Operator {
public:
    OpeDIV() : Operator(2) {}
    void ope() override;
    std::string toString() const { return "DIV"; }
    Operand* clone() { return new OpeDIV(*this); }
};

class OpeMOD : public Operator {
public:
    OpeMOD() : Operator(2) {}
    void ope() override;
    std::string toString() const { return "MOD"; }
    Operand* clone() { return new OpeMOD(*this); }
};

class OpeNOT: public Operator {
    unsigned int arite = 1;
public:
    OpeNOT() = default;
    void ope() override;
    std::string toString() const { return "NOT"; }
    Operand* clone() { return new OpeNOT(*this); }
};

class OpeNEG: public Operator {
    unsigned int arite = 1;
public:
    OpeNEG() = default;
    void ope() override;
    std::string toString() const { return "NEG"; }
    Operand* clone() { return new OpeNEG(*this); }
};

