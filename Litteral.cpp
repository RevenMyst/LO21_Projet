#include "Litteral.h"
#include <sstream>
#include<iostream>
#include "Visitor.h"
#include "Computer.h"

Litteral* operator+(const Litteral& lit1,const Litteral & lit2){
LitType classe1 = lit1.getClass();
LitType classe2 = lit2.getClass();
switch(classe1)
{
    case RATIONALLIT: {
        const RationalLit& nrtl =dynamic_cast<const RationalLit&>(lit1);
        switch(classe2) {
            case RATIONALLIT: {const RationalLit& nrtl2 =dynamic_cast<const RationalLit&>(lit2); return nrtl2+nrtl;} break;
            case REALLIT: {const RealLit& nrl2 =dynamic_cast<const RealLit&>(lit2); return nrl2+nrtl;} break;
            case INTLIT: {const IntLit& nil =dynamic_cast<const IntLit&>(lit2); return nil+nrtl;}  break;
        }
     } break;

    case REALLIT: {
        const RealLit& nrl =dynamic_cast<const RealLit&>(lit1);
        switch(classe2) {
            case RATIONALLIT: {const RationalLit& nrtl =dynamic_cast<const RationalLit&>(lit2); return nrl+nrtl;} break;
            case REALLIT: {const RealLit& nrl2 =dynamic_cast<const RealLit&>(lit2); return nrl2+nrl;} break;
            case INTLIT: {const IntLit& nil =dynamic_cast<const IntLit&>(lit2); return nil+nrl;}  break;
        }
        }break;

    case INTLIT: {
    const IntLit& nil =dynamic_cast<const IntLit&>(lit1);
     switch(classe2) {
            case RATIONALLIT: {const RationalLit& nrtl =dynamic_cast<const RationalLit&>(lit2); return nil+nrtl;} break;
            case REALLIT: {const RealLit& nrl2 =dynamic_cast<const RealLit&>(lit2); return nrl2+nil;} break;
            case INTLIT: {const IntLit& nil2 =dynamic_cast<const IntLit&>(lit2); return nil+nil2;}  break;
        }
    }break;

    default : {throw ComputerException("Littérales non compatibles avec l'opérateur '+'");} break;
}
}

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

void RealLit::accept(Visitor* visitor) const
{
	visitor->visitRealLit(this);
}


/*******************************/
/**SURCHARGE OPE ARITHMETIQUES**/
/*******************************/

//************OPERATEUR'+'**************
//INTLIT--------------------------------
NumLit* operator+(const IntLit & il,const IntLit & il2){
    /*Somme INTLIT-INLIT => INTLIT*/
    IntLit * nil = new IntLit(il.getValue() + il2.getValue());
    return nil;
}

NumLit* operator+(const IntLit & il,const RealLit & rl){
    /*Somme INTLIT-REALLIT => REALLIT*/
    RealLit * nrl = new RealLit(il.getValue() + rl.getValue());
    return nrl;
}

NumLit* operator+(const IntLit & il,const RationalLit & rtl){
    /*Somme INTLIT-RATIONALLIT => RATIONALLIT*/
        int newnum = il.getValue()*rtl.getDen() + rtl.getNum();
        int newden = rtl.getDen();
        RationalLit * nrtl = new RationalLit(newnum,newden);
        return nrtl;
}

//REALIT-------------------------------
NumLit* operator+(const RealLit & rl,const RealLit & rl2){
    /*Somme REALLIT-REALLIT => INTLIT SI MANTISSE = 0, REALLIT SINON*/

        double val = rl.getValue() + rl2.getValue();
        if(val-floor(val)==0){
            IntLit * it = new IntLit(val);
            return it;
        }
        else{
            RealLit * nrl = new RealLit(val);
            return nrl;
        }
}

NumLit* operator+(const RealLit & rl,const RationalLit & rtl){
    /*Somme REALLIT-REATIONALLIT => INTLIT SI MANTISSE = 0, REALLIT SINON*/
    double val = rl.getValue() + rtl.getValue();
        if(val-floor(val)==0){
            IntLit * it = new IntLit(val);
            return it;
        }
        else{
            RealLit * nrl = new RealLit(val);
            return nrl;
        }
}
NumLit* operator+(const RealLit & rl,const IntLit & il){
            return il+rl;
}


//RATIONALLIT--------------------------
NumLit* operator+(const RationalLit & rtl,const RationalLit & rtl2){
    /*Somme RATIONALLIT-RATIONALIT => RATIONALLIT */
    int newnum = rtl.getNum()*rtl2.getDen() + rtl2.getNum()*rtl.getDen();
    int newden= rtl2.getDen()*rtl.getDen();
    RationalLit * nrtl = new RationalLit(newnum,newden);
    return nrtl;
}
NumLit* operator+(const RationalLit & rtl,const IntLit & il){
    return il+rtl;
}
NumLit* operator+(const RationalLit & rtl,const RealLit & rl){
    return rl+rtl;
}


void RealLit::exec()
{
	if (getMant() != 0) {
		Litteral::exec();
	}
	else {
		IntLit* lit = new IntLit(getInt());
		lit->exec();
		delete this;
	}
}

/*******************************/
/*********RATIONALLIT***********/
/*******************************/


void RationalLit::accept(Visitor* visitor) const
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

void ProgLit::accept(Visitor* visitor) const
{
	visitor->visitProgLit(this);
}

void Litteral::exec()
{
	Computer::getInstance().getPile()->push(this);
}

void ExpLit::accept(Visitor* visitor) const
{
	visitor->visitExpLit(this);
}

void IntLit::accept(Visitor* visitor) const
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
