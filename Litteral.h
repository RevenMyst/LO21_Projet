#pragma once
#include "Operand.h"
#include <list>

const enum LitType { INTLIT, REALLIT, RATIONALLIT, EXPLIT, PROGLIT };


class Visitor;
class Litteral : public Operand
{
protected:
	unsigned int arite = 0;
	LitType type = INTLIT;
public:

	virtual void accept(Visitor* visitor) const = 0;
	LitType getClass() const { return type; }
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
	LitType type = EXPLIT;
public:
	ExpLit(std::string str) :name(str) {}
	std::string toString() const { return name; }
	void accept(Visitor* visitor) const;
	~ExpLit() = default;
	Operand* clone() { return new ExpLit(*this); }

};

class RealLit : public NumLit
{
	double value;
	LitType Type = REALLIT;
public:
	RealLit(double v) : value(v) {}
	int getInt() const { 
		return floor(value);
	}
	double getMant() const {
		return value-getInt();
	}
	double getValue() const { return value; }
	std::string toString() const;
	void accept(Visitor* visitor) const;
	~RealLit() = default;

	Operand* clone() { return new RealLit(*this); }
};

class RationalLit : public NumLit
{
	int numerateur;
	unsigned int denominateur;
	LitType Type = RATIONALLIT;
public:
	RationalLit(int n, unsigned int d) : numerateur(n), denominateur(d) {
		ReductionRational();
	}

	void accept(Visitor* visitor) const;
	void ReductionRational();
	int getNum() const { return numerateur; }
	unsigned int getDen() const { return denominateur; }
	double getValue() const;
	std::string toString() const;
	~RationalLit() = default;
	Operand* clone() { return new RationalLit(*this); }
};

class IntLit : public NumLit

{
	int value;
	LitType Type = INTLIT;
public:

	IntLit(int v) : value(v) {}
	void accept(Visitor* visitor) const;
	double getValue() const { return value; }
	int getInt() const { return value; } //retourne de valeur en int (pas de 1.0)
	std::string toString() const;
	~IntLit() = default;
	Operand* clone();

};

class ProgLit : public Litteral
{
private:
	std::list<Operand* > operands;
	LitType type = PROGLIT;
public:
	
	ProgLit() = default;
	ProgLit(const ProgLit& lit);
	void addOperand(Operand* o) {
		operands.push_back(o);
	}
	std::string toString() const;
	std::list<Operand*> getOperands() const { return operands; }
	void accept(Visitor* visitor) const;
	~ProgLit() {
		for (Operand* o : operands) {
			delete o;
		}
	}
	Operand* clone() { return new ProgLit(*this); }

};





