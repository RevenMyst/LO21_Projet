#include "Litteral.h"


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

double RealLit::getValue() const {

	std::string stringValue = RealLit::toString();
	double res = stod(stringValue);
	return(res);
}

std::string RealLit::toString() const {
	std::string valeur = std::to_string(integer);
	std::string virgule = std::to_string(mantisse);
	std::string dot = ".";
	if (virgule == "0" && valeur == "0")
	{
		return valeur.append("0.0");
	}
	else if (valeur == "0") {
		return dot.append(virgule);
	}
	else if (virgule == "0") {
		return valeur.append(dot);
	}
	else {
		return valeur.append(dot.append(virgule));
	}
}

/*******************************/
/*********RATIONALLIT***********/
/*******************************/


void RationalLit::ReductionRational() {
	for (int i = numerateur * denominateur; i > 1; i--) {
		if ((denominateur % i == 0) && (numerateur % i == 0)) {
			denominateur /= i;
			numerateur /= i;
		}
	}
}

double RationalLit::getValue() const {
	return(numerateur / denominateur);
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
