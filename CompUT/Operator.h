//////////////////////////////////////////////////////////////////////////////////////////////
///  <summary> Definit La classe mère Operator et chaque classe d'operateurs
///  + AtomLit (considere comme operateur) </summary>
///
/// <classes> Operator, AtomLit + sous-classes d'operator </classes>
///
///////////////////////////////////////////////////////////////////////////////////////////////
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
    virtual std::string toString() const override = 0;
    void exec() override;

};

class AtomLit : public Operator {
	std::string name;
public:
    AtomLit(std::string str) : Operator(0),name(str) {}
	~AtomLit() = default;
	void ope() override;
    std::string toString() const override { return name; }
	const std::string getValue() const { return name; }
    Operand* clone() override { return new AtomLit(*this); }
};

class OpeDUP : public Operator {
public:
	OpeDUP() : Operator(1){}
	void ope() override;
    std::string toString() const override { return "DUP"; }
    Operand* clone() override { return new OpeDUP(*this); }
};

class OpeDROP : public Operator {
public:
	OpeDROP() : Operator(1) {}
	void ope() override;
    std::string toString() const override { return "DROP"; }
    Operand* clone() override { return new OpeDROP(*this); }
};

class OpeCLEAR : public Operator {
public:
	OpeCLEAR() : Operator(1) {}
	void ope() override;
    std::string toString() const override { return "CLEAR"; }
    Operand* clone() override { return new OpeCLEAR(*this); }
};

class OpeSWAP : public Operator {
public:
	OpeSWAP() : Operator(2) {}
	void ope() override;
    std::string toString() const override { return "SWAP"; }
    Operand* clone() override { return new OpeSWAP(*this); }
};

class OpeSTO : public Operator {
public:
	OpeSTO() : Operator(2) {}
	void ope() override;
    std::string toString() const override { return "STO"; }
    Operand* clone() override { return new OpeSTO(*this); }
};

class OpeFORGET : public Operator, public Visitor {
public:
	OpeFORGET() : Operator(2) {}
	void ope() override;
	void visitExpLit(ExpLit* l1) override;
    std::string toString() const override { return "FORGET"; }
    Operand* clone() override { return new OpeFORGET(*this); }
};

class OpeEVAL : public Operator, public Visitor {
public:
	OpeEVAL() : Operator(1) {}
	void ope() override;
	void visitExpLit(ExpLit* l1) override;
	void visitProgLit(ProgLit* l1) override;
    std::string toString() const override { return "EVAL"; }
    Operand* clone() override { return new OpeEVAL(*this); }
};

class OpePlus : public Operator{
    public:
    OpePlus() : Operator(2) {}
    void ope()override;
    Operand* clone() override { return new OpePlus(*this); }
    std::string toString() const override { return "+"; }

    };
class OpeMul : public Operator{
    public:
    OpeMul() : Operator(2) {}
    void ope()override;
    Operand* clone() override { return new OpeMul(*this); }
    std::string toString() const override { return "*"; }

    };
class OpeMoins : public Operator{
    public:
    OpeMoins() : Operator(2) {}
    void ope()override;
    Operand* clone() override { return new OpeMoins(*this); }
    std::string toString() const override { return "-"; }

    };

class OpeDivision : public Operator{
    public:
    OpeDivision() : Operator(2) {}
    void ope()override;
    Operand* clone() override { return new OpeDivision(*this); }
    std::string toString() const override { return "/"; }

    };

class OpeAND : public Operator {
public:
    OpeAND() : Operator(2) {}
    void ope() override;
    std::string toString() const override { return "AND"; }
    Operand* clone() override { return new OpeAND(*this); }
};

class OpeOR : public Operator {
public:
    OpeOR() : Operator(2) {}
    void ope() override;
    std::string toString() const override { return "OR"; }
    Operand* clone() override { return new OpeOR(*this); }
};

class OpeEQUAL : public Operator {
public:
	OpeEQUAL() : Operator(2) {}
	void ope() override;
    std::string toString() const override { return "="; }
    Operand* clone() override { return new OpeEQUAL(*this); }
};

class OpeLTE : public Operator {
public:
	OpeLTE() : Operator(2) {}
	void ope() override;
    std::string toString() const override { return "<="; }
    Operand* clone() override { return new OpeLTE(*this); }
};

class OpeGTE : public Operator {
public:
	OpeGTE() : Operator(2) {}
	void ope() override;
    std::string toString() const override { return ">="; }
    Operand* clone() override { return new OpeGTE(*this); }
};

class OpeGT : public Operator {
public:
	OpeGT() : Operator(2) {}
	void ope() override;
    std::string toString() const override { return ">"; }
    Operand* clone() override { return new OpeGT(*this); }
};

class OpeLT : public Operator {
public:
	OpeLT() : Operator(2) {}
	void ope() override;
    std::string toString() const override { return "<"; }
    Operand* clone() override { return new OpeLT(*this); }
};

class OpeDIF : public Operator {
public:
	OpeDIF() : Operator(2) {}
	void ope() override;
    std::string toString() const override { return "!="; }
    Operand* clone() override { return new OpeDIF(*this); }
};

class OpeDIV : public Operator {
public:
    OpeDIV() : Operator(2) {}
    void ope() override;
    std::string toString() const override { return "DIV"; }
    Operand* clone() override { return new OpeDIV(*this); }
};

class OpeMOD : public Operator {
public:
    OpeMOD() : Operator(2) {}
    void ope() override;
    std::string toString() const override { return "MOD"; }
    Operand* clone() override { return new OpeMOD(*this); }
};

class OpeIFT : public Operator {
public:
    OpeIFT() : Operator(2) {}
    void ope() override;
    std::string toString() const override { return "IFT"; }
    Operand* clone() override { return new OpeIFT(*this); }
};

class OpeIFTE : public Operator {
public:
    OpeIFTE() : Operator(3) {}
    void ope() override;
    std::string toString() const override { return "IFTE"; }
    Operand* clone() override { return new OpeIFTE(*this); }
};

class OpeWHILE : public Operator {
public:
    OpeWHILE() : Operator(2) {}
    void ope() override;
    std::string toString() const override { return "WHILE"; }
    Operand* clone() override { return new OpeWHILE(*this); }
};

class OpeNOT: public Operator {
public:
    OpeNOT() : Operator(1) {}
    void ope() override;
    std::string toString() const override { return "NOT"; }
    Operand* clone() override { return new OpeNOT(*this); }
};

class OpeUNDO : public Operator {
public:
	OpeUNDO() : Operator(0) {}
	void ope() override;
    std::string toString() const override { return "UNDO"; }
    Operand* clone() override { return new OpeUNDO(*this); }
};

class OpeNEG: public Operator, public Visitor {
public:
    OpeNEG() : Operator(1) {}
    void ope() override;
    std::string toString() const override { return "NEG"; }
    Operand* clone() override { return new OpeNEG(*this); }
	void visitIntLit(IntLit* l1) override;
	void visitRealLit(RealLit* l1) override;
	void visitRationalLit(RationalLit* l1) override;
};

class OpeNUM: public Operator, public Visitor {
public:
    OpeNUM(): Operator(1) {}
    void ope() override;
    std::string toString() const override { return "NUM"; }
    Operand* clone() override { return new OpeNUM(*this); }
    void visitIntLit(IntLit* l1) override;
    void visitRationalLit(RationalLit* l1) override;
};

class OpeDEN: public Operator, public Visitor {
public:
    OpeDEN(): Operator(1) {}
    void ope() override;
    std::string toString() const override { return "DEN"; }
    Operand* clone() override { return new OpeDEN(*this); }
    void visitIntLit(IntLit* l1) override;
    void visitRationalLit(RationalLit* l1) override;
};


class OpePOW : public Operator {
public:
    OpePOW() : Operator(2) {}
    void ope() override;
    std::string toString() const override{ return "POW"; }
    Operand* clone() override{ return new OpePOW(*this); }
};

class OpeEXP : public Operator, public Visitor {
public:
        OpeEXP() : Operator(1) {}
		void ope() override;
        std::string toString() const override{ return "EXP"; }
        Operand* clone() override{ return new OpeEXP(*this); }
		void visitIntLit(IntLit* l1) override;
		void visitRealLit(RealLit* l1) override;
		void visitRationalLit(RationalLit* l1) override;
};

class OpeLN : public Operator, public Visitor {
public:
        OpeLN() : Operator(1) {}
        void ope() override;
        std::string toString() const override{ return "LN"; }
        Operand* clone() override{ return new OpeLN(*this); }
        void visitIntLit(IntLit* l1) override;
        void visitRealLit(RealLit* l1) override;
        void visitRationalLit(RationalLit* l1) override;
};

class OpeSQRT: public Operator, public Visitor {
public:
    OpeSQRT(): Operator(1) {}
    void ope() override;
    std::string toString() const override { return "SQRT"; }
    Operand* clone() override { return new OpeSQRT(*this); }
    void visitIntLit(IntLit* l1) override;
    void visitRealLit(RealLit* l1) override;
    void visitRationalLit(RationalLit* l1) override;
};

class OpeTrigonometry: public Operator, public Visitor {
    void pushValue(double x);
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
    std::string toString() const override { return "SIN"; }
    Operand* clone() override { return new OpeSIN(*this); }
};

class OpeCOS: public OpeTrigonometry {
public:
    double getResult(double x) override { return std::cos(x); }
    std::string toString() const override { return "COS"; }
    Operand* clone() override { return new OpeCOS(*this); }
};

class OpeTAN: public OpeTrigonometry {
public:
    double getResult(double x) override { return std::tan(x); }
    std::string toString() const override { return "TAN"; }
    Operand* clone() override { return new OpeTAN(*this); }
};

class OpeARCSIN: public OpeTrigonometry {
public:
    double getResult(double x) override { return std::asin(x); }
    std::string toString() const override{ return "ARCSIN"; }
    Operand* clone() override{ return new OpeARCSIN(*this); }
};

class OpeARCCOS: public OpeTrigonometry {
public:
    double getResult(double x) override { return std::acos(x); }
    std::string toString() const override{ return "ARCCOS"; }
    Operand* clone() override{ return new OpeARCCOS(*this); }
};

class OpeARCTAN: public OpeTrigonometry {
public:
    double getResult(double x) override { return std::atan(x); }
    std::string toString() const override{ return "ARCTAN"; }
    Operand* clone() override{ return new OpeARCTAN(*this); }
};
