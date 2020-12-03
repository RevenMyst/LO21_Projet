#pragma once
#include "Operand.h"
#include <list>
#include <cmath>
#include "ComputerException.h"

using namespace std;

enum LitType { INTLIT, REALLIT, RATIONALLIT, EXPLIT, PROGLIT };


class Visitor;
class Litteral : public Operand
{
protected:
	unsigned int arite = 0;
public:

	virtual void accept(Visitor* visitor) = 0;
	virtual LitType getClass() const = 0;
	void exec() override;
};

bool operator==(const Litteral& lit1, const Litteral& lit2);
bool operator!=(const Litteral& lit1, const Litteral& lit2);
bool operator>=(const Litteral& lit1, const Litteral& lit2);
bool operator<=(const Litteral& lit1, const Litteral& lit2);
bool operator>(const Litteral& lit1, const Litteral& lit2);
bool operator<(const Litteral& lit1, const Litteral& lit2);

class NumLit : public Litteral
{
public:
	virtual double getValue() const = 0;
};

class ExpLit : public Litteral
{
	std::string name;
public:
	ExpLit(std::string str) :name(str) {}
	std::string toString() const override{ return "'"+name+"'"; }
	const std::string getValue() const { return name; }
	void accept(Visitor* visitor);
	~ExpLit() = default;
	LitType getClass() const { return EXPLIT; }
	Operand* clone() { return new ExpLit(*this); }

};

class RealLit : public NumLit
{
	double value;
public:
	RealLit(double v) : value(v) {}
	int getInt() const {
		return (int) floor(value);
	}
	double getMant() const {
		return value-getInt();
	}
	double getValue() const { return value; }
	std::string toString() const;
	void accept(Visitor* visitor);
	~RealLit() = default;
	LitType getClass() const { return REALLIT; }
	Operand* clone() { return new RealLit(*this); }
};

class RationalLit : public NumLit
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

	void accept(Visitor* visitor);
	void ReductionRational();
	int getNum() const { return numerateur; }
	int getDen() const { return denominateur; }
	double getValue() const;
	std::string toString() const;
	~RationalLit() = default;
	LitType getClass() const { return RATIONALLIT; }
	Operand* clone() { return new RationalLit(*this); }
};

class IntLit : public NumLit

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
	std::string toString() const;
	std::list<Operand*> getOperands() const { return operands; }
	void accept(Visitor* visitor);
	~ProgLit() {
		for (Operand* o : operands) {
			delete o;
		}
	}
	LitType getClass() const { return PROGLIT; }
	Operand* clone() { return new ProgLit(*this); }

};
