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
/// superclass de tous les operateurs
class Operator : public Operand
{
private:
	unsigned int arite;
    //verifie quil reste assez d'elements dans la pile
	bool verify();
protected:
	virtual void ope() = 0;
public:
	Operator(unsigned int a):arite(a){}
    virtual std::string toString() const override = 0;
    void exec() override;

};
/// Représente un variable a compiler lors de l'execution
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
/// Operator de duplication de la tete de pile
class OpeDUP : public Operator {
public:
	OpeDUP() : Operator(1){}
	void ope() override;
    std::string toString() const override { return "DUP"; }
    Operand* clone() override { return new OpeDUP(*this); }
};
/// Operator de suppression de la tete de pile
class OpeDROP : public Operator {
public:
	OpeDROP() : Operator(1) {}
	void ope() override;
    std::string toString() const override { return "DROP"; }
    Operand* clone() override { return new OpeDROP(*this); }
};
/// Operator de vidange de pile
class OpeCLEAR : public Operator {
public:
	OpeCLEAR() : Operator(1) {}
	void ope() override;
    std::string toString() const override { return "CLEAR"; }
    Operand* clone() override { return new OpeCLEAR(*this); }
};
/// Operator qui echange les 2 premiers elements de la pile
class OpeSWAP : public Operator {
public:
	OpeSWAP() : Operator(2) {}
	void ope() override;
    std::string toString() const override { return "SWAP"; }
    Operand* clone() override { return new OpeSWAP(*this); }
};
/// Operator de stockage de variable
class OpeSTO : public Operator {
public:
	OpeSTO() : Operator(2) {}
	void ope() override;
    std::string toString() const override { return "STO"; }
    Operand* clone() override { return new OpeSTO(*this); }
};
/// Operator de destruction de variable
class OpeFORGET : public Operator, public Visitor {
public:
    OpeFORGET() : Operator(1) {}
	void ope() override;
	void visitExpLit(ExpLit* l1) override;
    std::string toString() const override { return "FORGET"; }
    Operand* clone() override { return new OpeFORGET(*this); }
};
/// Operator d'evaluation d'expression on de programme
class OpeEVAL : public Operator, public Visitor {
public:
	OpeEVAL() : Operator(1) {}
	void ope() override;
	void visitExpLit(ExpLit* l1) override;
	void visitProgLit(ProgLit* l1) override;
    std::string toString() const override { return "EVAL"; }
    Operand* clone() override { return new OpeEVAL(*this); }
};
/// Operator d'addition
class OpePlus : public Operator{
    public:
    OpePlus() : Operator(2) {}
    void ope()override;
    Operand* clone() override { return new OpePlus(*this); }
    std::string toString() const override { return "+"; }

    };
///Operator de multiplication
class OpeMul : public Operator{
    public:
    OpeMul() : Operator(2) {}
    void ope()override;
    Operand* clone() override { return new OpeMul(*this); }
    std::string toString() const override { return "*"; }

    };
/// Operator de soustraction
class OpeMoins : public Operator{
    public:
    OpeMoins() : Operator(2) {}
    void ope()override;
    Operand* clone() override { return new OpeMoins(*this); }
    std::string toString() const override { return "-"; }

    };
/// Operator de division
class OpeDivision : public Operator{
    public:
    OpeDivision() : Operator(2) {}
    void ope()override;
    Operand* clone() override { return new OpeDivision(*this); }
    std::string toString() const override { return "/"; }

    };
/// Operator de ET logique
class OpeAND : public Operator {
public:
    OpeAND() : Operator(2) {}
    void ope() override;
    std::string toString() const override { return "AND"; }
    Operand* clone() override { return new OpeAND(*this); }
};
/// Operator de OU logique
class OpeOR : public Operator {
public:
    OpeOR() : Operator(2) {}
    void ope() override;
    std::string toString() const override { return "OR"; }
    Operand* clone() override { return new OpeOR(*this); }
};
/// Operator de comparaison logique et arithmetique
class OpeEQUAL : public Operator {
public:
	OpeEQUAL() : Operator(2) {}
	void ope() override;
    std::string toString() const override { return "="; }
    Operand* clone() override { return new OpeEQUAL(*this); }
};
/// Operator inferieur ou egal
class OpeLTE : public Operator {
public:
	OpeLTE() : Operator(2) {}
	void ope() override;
    std::string toString() const override { return "<="; }
    Operand* clone() override { return new OpeLTE(*this); }
};
/// Operator superieur ou egal
class OpeGTE : public Operator {
public:
	OpeGTE() : Operator(2) {}
	void ope() override;
    std::string toString() const override { return ">="; }
    Operand* clone() override { return new OpeGTE(*this); }
};
/// Operator superieur
class OpeGT : public Operator {
public:
	OpeGT() : Operator(2) {}
	void ope() override;
    std::string toString() const override { return ">"; }
    Operand* clone() override { return new OpeGT(*this); }
};
/// Operator inferieur
class OpeLT : public Operator {
public:
	OpeLT() : Operator(2) {}
	void ope() override;
    std::string toString() const override { return "<"; }
    Operand* clone() override { return new OpeLT(*this); }
};
/// Operator de difference logique et arithmetique
class OpeDIF : public Operator {
public:
	OpeDIF() : Operator(2) {}
	void ope() override;
    std::string toString() const override { return "!="; }
    Operand* clone() override { return new OpeDIF(*this); }
};
/// Operator de division entiere
class OpeDIV : public Operator {
public:
    OpeDIV() : Operator(2) {}
    void ope() override;
    std::string toString() const override { return "DIV"; }
    Operand* clone() override { return new OpeDIV(*this); }
};
/// Operator de modulo
class OpeMOD : public Operator {
public:
    OpeMOD() : Operator(2) {}
    void ope() override;
    std::string toString() const override { return "MOD"; }
    Operand* clone() override { return new OpeMOD(*this); }
};
/// Operator de condition if then
class OpeIFT : public Operator {
public:
    OpeIFT() : Operator(2) {}
    void ope() override;
    std::string toString() const override { return "IFT"; }
    Operand* clone() override { return new OpeIFT(*this); }
};
/// Operator de condition if then else
class OpeIFTE : public Operator {
public:
    OpeIFTE() : Operator(3) {}
    void ope() override;
    std::string toString() const override { return "IFTE"; }
    Operand* clone() override { return new OpeIFTE(*this); }
};
///Operator de boucle
class OpeWHILE : public Operator {
public:
    OpeWHILE() : Operator(2) {}
    void ope() override;
    std::string toString() const override { return "WHILE"; }
    Operand* clone() override { return new OpeWHILE(*this); }
};
/// Operator de NON logique
class OpeNOT: public Operator {
public:
    OpeNOT() : Operator(1) {}
    void ope() override;
    std::string toString() const override { return "NOT"; }
    Operand* clone() override { return new OpeNOT(*this); }
};
/// Operator de retour arriere
class OpeUNDO : public Operator {
public:
	OpeUNDO() : Operator(0) {}
	void ope() override;
    std::string toString() const override { return "UNDO"; }
    Operand* clone() override { return new OpeUNDO(*this); }
};
/// Operator de negation arithmétique ( x -1 )
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
/// Operator qui recupere le numerateur
class OpeNUM: public Operator, public Visitor {
public:
    OpeNUM(): Operator(1) {}
    void ope() override;
    std::string toString() const override { return "NUM"; }
    Operand* clone() override { return new OpeNUM(*this); }
    void visitIntLit(IntLit* l1) override;
    void visitRationalLit(RationalLit* l1) override;
};
/// Operator qui recupere le denominateur
class OpeDEN: public Operator, public Visitor {
public:
    OpeDEN(): Operator(1) {}
    void ope() override;
    std::string toString() const override { return "DEN"; }
    Operand* clone() override { return new OpeDEN(*this); }
    void visitIntLit(IntLit* l1) override;
    void visitRationalLit(RationalLit* l1) override;
};
/// Operator de mise a la puissance
class OpePOW : public Operator {
public:
    OpePOW() : Operator(2) {}
    void ope() override;
    std::string toString() const override{ return "POW"; }
    Operand* clone() override{ return new OpePOW(*this); }
};
/// Operator d'exponentielle
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
/// Operator de logarithme neperien
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
/// Operator de racine carre
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
/// superclass des Operator trigonometrique
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
/// Operator trigonometrique de sinus
class OpeSIN: public OpeTrigonometry {
public:
    double getResult(double x) override { return std::sin(x); }
    std::string toString() const override { return "SIN"; }
    Operand* clone() override { return new OpeSIN(*this); }
};
/// Operator trigonometrique de cosinus
class OpeCOS: public OpeTrigonometry {
public:
    double getResult(double x) override { return std::cos(x); }
    std::string toString() const override { return "COS"; }
    Operand* clone() override { return new OpeCOS(*this); }
};
/// Operator trigonometrique de tangente
class OpeTAN: public OpeTrigonometry {
public:
    double getResult(double x) override { return std::tan(x); }
    std::string toString() const override { return "TAN"; }
    Operand* clone() override { return new OpeTAN(*this); }
};
/// Operator trigonometrique de arc sinus
class OpeARCSIN: public OpeTrigonometry {
public:
    double getResult(double x) override {
        if(x>-1&&x<=1){
            return std::asin(x);
        }else{
            throw ComputerException("Pour ARCSIN la valeur doit etre comprise entre -1 et 1");
        }}
    std::string toString() const override{ return "ARCSIN"; }
    Operand* clone() override{ return new OpeARCSIN(*this); }
};
/// Operator trigonometrique de arc cosinus
class OpeARCCOS: public OpeTrigonometry {
public:
    double getResult(double x) override {
        if(x>-1&&x<=1){
            return std::acos(x);
        }else{
            throw ComputerException("Pour ARCCOS la valeur doit etre comprise entre -1 et 1");
        }
        }
    std::string toString() const override{ return "ARCCOS"; }
    Operand* clone() override{ return new OpeARCCOS(*this); }
};
/// Operator trigonometrique de arc tangente
class OpeARCTAN: public OpeTrigonometry {
public:
    double getResult(double x) override {
        if(x>-1&&x<=1){
            return std::atan(x);
        }else{
            throw ComputerException("Pour ARCTAN la valeur doit etre comprise entre -1 et 1");
        }}
    std::string toString() const override{ return "ARCTAN"; }
    Operand* clone() override{ return new OpeARCTAN(*this); }
};
