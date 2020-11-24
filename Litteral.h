#pragma once
#include "Operand.h"
#include "visitor.h"
#include <vector>

const enum LitType { INTLIT, REALLIT, RATIONALLIT, EXPLIT, PROGLIT };


class Litteral : public Operand
{
protected:
	unsigned int arite = 0;
	LitType type = INTLIT;
public:

	virtual void accept(Visitor* visitor) const = 0;
	LitType getClass() const { return type; }
	void exec() override { Computer::getInstance().getPile()->push(this); };
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
	void accept(Visitor* visitor) const { visitor->visitExpLit(this); }
	~ExpLit() = default;
	Operand* clone() { return new ExpLit(*this); }

};

class RealLit : public NumLit
{
	int integer;
	unsigned int mantisse;
	LitType Type = REALLIT;
public:
	RealLit(int i, unsigned int m) : integer(i), mantisse(m) {}
	int getInt() const { return integer; }
	unsigned int getMant() const { return mantisse; }
	double getValue() const;
	std::string toString() const;
	void accept(Visitor* visitor) const { visitor->visitRealLit(this); }
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

	void accept(Visitor* visitor) const{ visitor->visitRationalLit(this); }
	void ReductionRational();
	int getNum() const { return numerateur; }
	unsigned int getDen() const { return denominateur; }
	double getValue() const;
	std::string toString() const {
		//Cas d'ou on a un entier
		if (getDen() == 1)
			return(std::to_string(getNum()));
		//Cas d'ou on a meme valeur dans les deux parties ex: 5/5
		if (getDen() == getNum())
			return("1");
		std::string res = std::to_string(getNum()) + "/" + std::to_string(getDen());
		return(res);
	}
	~RationalLit() = default;
	Operand* clone() { return new RationalLit(*this); }
};

class IntLit : public NumLit

{
	int value;
	LitType Type = INTLIT;
public:

	IntLit(int v) : value(v) {}
	void accept(Visitor* visitor) const { visitor->visitIntLit(this); }
	double getValue() const { return value; }
	int getInt() const { return value; } //retourne de valeur en int (pas de 1.0)
	std::string toString() const {
		std::string res = std::to_string(getInt());
		return(res);
	}
	~IntLit() = default;
	Operand* clone() { return new IntLit(*this); }

};

class ProgLit : public Litteral
{
private:
	std::vector<Operand* > operands;
	LitType type = PROGLIT;
public:
	
	ProgLit() = default;
	ProgLit(const ProgLit& lit);
	void addOperand(Operand* o) {
		operands.push_back(o);
	}
	std::string toString() const;
	std::vector<Operand*> getOperands() const { return operands; }
	void accept(Visitor* visitor) const override { visitor->visitProgLit(this); }
	~ProgLit() {
		for (Operand* o : operands) {
			delete o;
		}
	}
	Operand* clone() { return new ProgLit(*this); }

};





