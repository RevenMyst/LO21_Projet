//////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> Definit les differents types de litterales </summary>
///
/// <classes> Litteral, NumLit, CompLit, IntLit, RealLit, RationalLit, ExpLit, ProgLit </classes>
///
/// <enum> LitType </enum>
///
///////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Operand.h"
#include "ComputerException.h"
#include <list>
#include <cmath>
#include "ComputerException.h"

using namespace std;

enum LitType { INTLIT, REALLIT, RATIONALLIT, EXPLIT, PROGLIT};


class Visitor;

class Litteral : public Operand
{
protected:
    std::string reduceString();
public:
    virtual std::string toPileString();
	virtual void accept(Visitor* visitor) = 0;
	virtual LitType getClass() const = 0;
	void exec() override;
};


class CompLit{
public:
	virtual double getComparableValue() = 0;
};

class NumLit {
public:
	virtual double getValue() const = 0;

};


class ExpLit : public Litteral
{
	std::string name;
public:
	ExpLit(std::string str) :name(str) {}
	std::string toString() const override{ return "'"+name+"'"; }
    std::string toPileString() override;
	const std::string getValue() const { return name; }
    void accept(Visitor* visitor) override;
	~ExpLit() = default;
    LitType getClass() const override{ return EXPLIT; }
    Operand* clone() override{ return new ExpLit(*this); }
    void compile();
};

class RealLit : public Litteral, public CompLit, public NumLit
{
	float value;
public:
	RealLit(float v) : value(v) {}
    int getInt() const {return (int)floor(value);}
	double getMant() const {return value-getInt();}
    double getValue() const override{ return value; }
    std::string toString() const override;
    void accept(Visitor* visitor) override;
	void exec() override;
	~RealLit() = default;
    LitType getClass() const override{ return REALLIT; }
    Operand* clone() override{ return new RealLit(*this); }
    double getComparableValue() override{ return value; }


};

class RationalLit : public Litteral, public CompLit, public NumLit
{
	int numerateur;
	int denominateur;
public:
	RationalLit(int n, int d) : numerateur(n), denominateur(d) {
        ReductionRational();
		if (denominateur == 0) throw ComputerException("erreur, pas possible d'avoir un division par 0");
		if (denominateur < 0) {
			denominateur *= -1;
			numerateur *= -1;
		}
	}
    void exec() override;
    void accept(Visitor* visitor) override;
	void ReductionRational();
	int getNum() const { return numerateur; }
	int getDen() const { return denominateur; }
    double getValue() const override;
    std::string toString() const override;
	~RationalLit() = default;
    LitType getClass() const override{ return RATIONALLIT; }
    Operand* clone() override{ return new RationalLit(*this); }
    double getComparableValue() override{ return (numerateur / denominateur); }
};

class IntLit : public Litteral, public CompLit, public NumLit
{
	int value;
public:

	IntLit(int v) : value(v) {}
	void accept(Visitor* visitor);
	double getValue() const { return value; }
	int getInt() const { return value; } //retourne de valeur en int (pas de 1.0)
	std::string toString() const;
	~IntLit() = default;
	LitType getClass() const { return INTLIT; }
	Operand* clone();
	double getComparableValue() { return value; }


};


class ProgLit : public Litteral
{
private:
	std::list<Operand* > operands;
public:

	ProgLit() = default;
	ProgLit(const ProgLit& lit);
	void addOperand(Operand* o) {
		operands.push_back(o);
	}
    std::string toPileString() override;
    std::string toString() const override;
	void compile();
	std::list<Operand*> getOperands() const { return operands; }
    void accept(Visitor* visitor) override;
	~ProgLit() {
		for (Operand* o : operands) {
			delete o;
		}
	}
    LitType getClass() const override{ return PROGLIT; }
    Operand* clone() override{ return new ProgLit(*this); }
};
