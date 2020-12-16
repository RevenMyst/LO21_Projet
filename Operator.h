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

class AtomLit : public Operator {
	std::string name;
public:
	AtomLit(std::string str) : name(str), Operator(0) {}
	~AtomLit() = default;
	void ope() override;
	std::string toString() const { return name; }
	const std::string getValue() const { return name; }
	Operand* clone() { return new AtomLit(*this); }
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

class OpePlus : public Operator{
    public:
    OpePlus() : Operator(2) {}
    void ope()override;
    Operand* clone() { return new OpePlus(*this); }
    std::string toString() const { return "+"; }

    };
class OpeMul : public Operator{
    public:
    OpeMul() : Operator(2) {}
    void ope()override;
    Operand* clone() { return new OpeMul(*this); }
    std::string toString() const { return "*"; }

    };
class OpeMoins : public Operator{
    public:
    OpeMoins() : Operator(2) {}
    void ope()override;
    Operand* clone() { return new OpeMoins(*this); }
    std::string toString() const { return "-"; }

    };

class OpeDivision : public Operator{
    public:
    OpeDivision() : Operator(2) {}
    void ope()override;
    Operand* clone() { return new OpeDivision(*this); }
    std::string toString() const { return "/"; }

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

class OpeIFT : public Operator {
public:
    OpeIFT() : Operator(2) {}
    void ope() override;
    std::string toString() const { return "IFT"; }
    Operand* clone() { return new OpeIFT(*this); }
};

class OpeIFTE : public Operator {
public:
    OpeIFTE() : Operator(3) {}
    void ope() override;
    std::string toString() const { return "IFTE"; }
    Operand* clone() { return new OpeIFTE(*this); }
};

class OpeNOT: public Operator {
public:
    OpeNOT() : Operator(1) {}
    void ope() override;
    std::string toString() const { return "NOT"; }
    Operand* clone() { return new OpeNOT(*this); }
};

class OpeUNDO : public Operator {
public:
	OpeUNDO() : Operator(0) {}
	void ope() override;
	std::string toString() const { return "UNDO"; }
	Operand* clone() { return new OpeUNDO(*this); }
};

class OpeNEG: public Operator, public Visitor {
public:
    OpeNEG() : Operator(1) {}
    void ope() override;
    std::string toString() const { return "NEG"; }
    Operand* clone() { return new OpeNEG(*this); }
	void visitIntLit(IntLit* l1) override;
	void visitRealLit(RealLit* l1) override;
	void visitRationalLit(RationalLit* l1) override;
};

class OpeNUM: public Operator, public Visitor {
public:
    OpeNUM(): Operator(1) {}
    void ope() override;
    std::string toString() const { return "NUM"; }
    Operand* clone() { return new OpeNUM(*this); }
    void visitIntLit(IntLit* l1) override;
    void visitRationalLit(RationalLit* l1) override;
};

class OpeDEN: public Operator, public Visitor {
public:
    OpeDEN(): Operator(1) {}
    void ope() override;
    std::string toString() const { return "DEN"; }
    Operand* clone() { return new OpeDEN(*this); }
    void visitIntLit(IntLit* l1) override;
    void visitRationalLit(RationalLit* l1) override;
};


class OpePOW : public Operator {
public:
    OpePOW() : Operator(2) {}
    void ope() override;
    std::string toString() const { return "POW"; }
    Operand* clone() { return new OpePOW(*this); }
};

class OpeSQRT: public Operator, public Visitor {
public:
    OpeSQRT(): Operator(1) {}
    void ope() override;
    std::string toString() const { return "SQRT"; }
    Operand* clone() { return new OpeSQRT(*this); }
    void visitIntLit(IntLit* l1) override;
    void visitRealLit(RealLit* l1) override;
    void visitRationalLit(RationalLit* l1) override;
};

class OpeTrigonometry: public Operator, public Visitor {
protected:
    virtual double getResult(double x) = 0;
public:
    OpeTrigonometry(): Operator(1) {}
    void ope() override;
    void visitIntLit(IntLit* l1) override;
    void visitRealLit(RealLit* l1) override;
    void visitRationalLit(RationalLit* l1) override;
};

class OpeSIN: public OpeTrigonometry {
public:
    double getResult(double x) override { return std::sin(x); }
    std::string toString() const { return "SIN"; }
    Operand* clone() { return new OpeSIN(*this); }
};

class OpeCOS: public OpeTrigonometry {
public:
    double getResult(double x) override { return std::cos(x); }
    std::string toString() const { return "COS"; }
    Operand* clone() { return new OpeCOS(*this); }
};

class OpeTAN: public OpeTrigonometry {
public:
    double getResult(double x) override { return std::tan(x); }
    std::string toString() const { return "TAN"; }
    Operand* clone() { return new OpeTAN(*this); }
};
