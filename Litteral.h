#pragma once
#include "Operand.h"
#include <list>
#include <tgmath.h>

enum LitType { INTLIT, REALLIT, RATIONALLIT, EXPLIT, PROGLIT };


class Visitor;
class Litteral : public Operand
{
protected:
	unsigned int arite = 0;
public:

	virtual void accept(Visitor* visitor) const = 0;
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
    NumLit* operator+(const NumLit & l) const;

};

class ExpLit : public Litteral
{
	std::string name;
public:
	ExpLit(std::string str) :name(str) {}
	std::string toString() const override{ return "'"+name+"'"; }
	const std::string getValue() const { return name; }
	void accept(Visitor* visitor) const;
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
		return floor(value);
	}
	double getMant() const {
		return value-getInt();
	}
	double getValue() const { return value; }
	std::string toString() const;
	void accept(Visitor* visitor) const;
	~RealLit() = default;
	LitType getClass() const { return REALLIT; }
	Operand* clone() { return new RealLit(*this); }
    NumLit*operator+(const NumLit & l) const;
    NumLit& operator-(const NumLit &l) const;
    NumLit& operator*(const NumLit & l) const;
    NumLit& operator/(const NumLit & l) const;
};

class RationalLit : public NumLit
{
	int numerateur;
	unsigned int denominateur;
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
	LitType getClass() const { return RATIONALLIT; }
	Operand* clone() { return new RationalLit(*this); }
    NumLit*operator+(const NumLit & l) const;
    NumLit& operator-(const NumLit &l) const;
    NumLit& operator*(const NumLit & l) const;
    NumLit& operator/(const NumLit & l) const;
};

class IntLit : public NumLit

{
	int value;
public:

	IntLit(int v) : value(v) {}
	void accept(Visitor* visitor) const;
	double getValue() const { return value; }
	int getInt() const { return value; } //retourne de valeur en int (pas de 1.0)
	std::string toString() const;
	~IntLit() = default;
	LitType getClass() const { return INTLIT; }
	Operand* clone();
    NumLit*operator+(const NumLit & l) const;
    NumLit& operator-(const NumLit &l) const;
    NumLit& operator*(const NumLit & l) const;
    NumLit& operator/(const NumLit & l) const;

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
	void accept(Visitor* visitor) const;
	~ProgLit() {
		for (Operand* o : operands) {
			delete o;
		}
	}
	LitType getClass() const { return PROGLIT; }
	Operand* clone() { return new ProgLit(*this); }

};





