#include "Litteral.h"
#include <sstream>
#include "Visitor.h"
#include "Computer.h"

bool operator==(const Litteral& lit1, const Litteral& lit2)
{
	// si variable numeriques : cast et compare valeurs
	if (lit1.getClass() != EXPLIT && lit2.getClass() != EXPLIT && lit1.getClass() != PROGLIT && lit2.getClass() != PROGLIT) {
		return (dynamic_cast<const NumLit&>(lit1).getValue() == dynamic_cast<const NumLit&>(lit2).getValue());
	}
	else {
		// sinon compare string value (2 programme identiques on la meme string value
		return lit1.toString() == lit2.toString();
	}
	return false;
}

bool operator!=(const Litteral& lit1, const Litteral& lit2)
{
	if (lit1.getClass() != EXPLIT && lit2.getClass() != EXPLIT && lit1.getClass() != PROGLIT && lit2.getClass() != PROGLIT) {
		return (dynamic_cast<const NumLit&>(lit1).getValue() != dynamic_cast<const NumLit&>(lit2).getValue());
	}
	else {
		return lit1.toString() != lit2.toString();
	}
}
// pour les operateurs < > <= >= on ne peux comparer que les variables numeriques
bool operator>=(const Litteral& lit1, const Litteral& lit2)
{
	if (lit1.getClass() != EXPLIT && lit2.getClass() != EXPLIT && lit1.getClass() != PROGLIT && lit2.getClass() != PROGLIT)
		return (dynamic_cast<const NumLit&>(lit1).getValue() >= dynamic_cast<const NumLit&>(lit2).getValue());
	return false;
}

bool operator<=(const Litteral& lit1, const Litteral& lit2)
{
	if (lit1.getClass() != EXPLIT && lit2.getClass() != EXPLIT && lit1.getClass() != PROGLIT && lit2.getClass() != PROGLIT)
		return (dynamic_cast<const NumLit&>(lit1).getValue() <= dynamic_cast<const NumLit&>(lit2).getValue());
	return false;
}

bool operator<(const Litteral& lit1, const Litteral& lit2)
{
	if (lit1.getClass() != EXPLIT && lit2.getClass() != EXPLIT && lit1.getClass() != PROGLIT && lit2.getClass() != PROGLIT)
		return (dynamic_cast<const NumLit&>(lit1).getValue() < dynamic_cast<const NumLit&>(lit2).getValue());
	return false;
}

bool operator>(const Litteral& lit1, const Litteral& lit2)
{
	if (lit1.getClass() != EXPLIT && lit2.getClass() != EXPLIT && lit1.getClass() != PROGLIT && lit2.getClass() != PROGLIT)
		return (dynamic_cast<const NumLit&>(lit1).getValue() > dynamic_cast<const NumLit&>(lit2).getValue());
	return false;
}

/*******************************/
/***********REALLIT*************/
/*******************************/

std::string RealLit::toString() const {
	std::ostringstream ss;
	if (getMant() == 0) {
		return std::to_string(getInt()) + ".";
	}
	else if (getInt() == 0) {
		ss << getMant();
		std::string str = ss.str();
		str.erase(0, 1);
		return str;
	}
	else {
		ss << value;
		return ss.str();
	}
}

void RealLit::accept(Visitor* visitor)
{
	visitor->visitRealLit(this);
}

/*******************************/
/*********RATIONALLIT***********/
/*******************************/


void RationalLit::accept(Visitor* visitor)
{
	visitor->visitRationalLit(this);
}

void RationalLit::ReductionRational() {
	for (int i = numerateur * denominateur; i > 1; i--) {
		if ((denominateur % i == 0) && (numerateur % i == 0)) {
			denominateur /= i;
			numerateur /= i;
		}
	}
}

double RationalLit::getValue() const {

	return (numerateur / (double)denominateur);
}

std::string RationalLit::toString() const
{
	//Cas d'ou on a un entier
	if (getDen() == 1)
		return(std::to_string(getNum()));
	//Cas d'ou on a meme valeur dans les deux parties ex: 5/5
	if (getDen() == getNum())
		return("1");
	std::string res = std::to_string(getNum()) + "/" + std::to_string(getDen());
	return(res);
}

/*******************************/
/***********PROGLIT*************/
/*******************************/

ProgLit::ProgLit(const ProgLit& lit)
{
	for (Operand* o : lit.getOperands()) {
		this->addOperand(o->clone());
	}
}

std::string ProgLit::toString() const
{
	std::string str = "[ ";
	for (Operand* o : operands) {
		str = str + o->toString() + " ";
	}
	str += "]";
	return str;
}

void ProgLit::accept(Visitor* visitor)
{
	visitor->visitProgLit(this);
}

void Litteral::exec()
{
	Computer::getInstance().getPile()->push(this);
}

void ExpLit::accept(Visitor* visitor)
{
	visitor->visitExpLit(this);
}

void IntLit::accept(Visitor* visitor)
{
	visitor->visitIntLit(this);
}

std::string IntLit::toString() const
{
	std::string res = std::to_string(getInt());
	return(res);
}

Operand* IntLit::clone()
{
	return new IntLit(*this);
}
