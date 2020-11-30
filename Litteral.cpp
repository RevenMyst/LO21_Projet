#include "Litteral.h"
#include <sstream>
#include<iostream>
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

void RealLit::accept(Visitor* visitor) const
{
	visitor->visitRealLit(this);
}

//NUMLIT-------------------------------
//Surcharge des op�rateurs arithm�tiques
NumLit* NumLit::operator+(const NumLit & l)const{
LitType classe1 = this->getClass();
LitType classe2 = l.getClass();
std::cout<<"ok++"<<std::endl;

if(classe1==REALLIT){
std::cout<<"cas real----------------"<<std::endl;

    switch(classe2){

    case REALLIT :
       {

        const RealLit& nl =dynamic_cast<const RealLit&>(l);
        double val = nl.getValue() + this->getValue();
        // Si la mantisse vaut 0 on cr�e un INTLIT, sinon un REALLIT
        if(val-floor(val)==0){
            std::cout<<"Cr�e Int"<<std::endl;
            IntLit * it = new IntLit(val);
            return it;
        }
        else{
            RealLit * rl = new RealLit(val);
            return rl;
        }
       }
        break;

   case INTLIT:
    {

    const IntLit& nl =dynamic_cast<const IntLit&>(l);
        double val = nl.getValue() + this->getValue();
        // Si la mantisse vaut 0 on cr�e un INTLIT, sinon un REALLIT
            std::cout<<"+ok"<<std::endl;
            RealLit * rl = new RealLit(val);
            return rl;
    }
        break;


    case RATIONALLIT :
        {
        const RationalLit& nl =dynamic_cast<const RationalLit&>(l);
        double val = nl.getValue() + this->getValue();
        /*On est oblig� de cr�er un r�el dans un premier temps
        car sinon probl�me dans le cas ou on additionne un r��l
        et une fraction et que la mantisse vaut 0*/
        RealLit * rl = new RealLit(val);
        std::cout<<"cree real"<<rl->getInt()<<" ,"<<rl->getMant()<<std::endl;

        if(rl->getMant() ==0){
            std::cout<<"cree int"<<std::endl;
            IntLit * it = new IntLit(val);
            return it;
        }

        return rl;

        break;
        }
    }//Fin du switch
}//Fin test avec real

//TEST AVEC UN INTLIT ------------------------------
    if(classe1==INTLIT){
std::cout<<"cas int ----------"<<std::endl;

    switch(classe2){

    case REALLIT :
       {
        std::cout<<"cas int - reel"<<std::endl;

        const RealLit& nl =dynamic_cast<const RealLit&>(l);
        double val = nl.getValue() + this->getValue();

        //On suppose qu'un r�el + un entier donnera toujours un reel
            RealLit * rl = new RealLit(val);
            return rl;
        }

        break;

   case INTLIT:
    {

    const IntLit& nl =dynamic_cast<const IntLit&>(l);
        double val = nl.getValue() + this->getValue();
    //Un intlit + un intlit donnera un intlit
            IntLit * rl = new IntLit(val);
            return rl;
    }
        break;


    case RATIONALLIT :
        {
        std::cout<<" cas int ratio"<<std::endl;

        const RationalLit& nl =dynamic_cast<const RationalLit&>(l);
        //Un i=IntLit + un RationalLit donne toujours un RationnalLit
        std::cout<<"cas int - rationnelle"<<std::endl;
        int val = this->getValue();
        int newnum = val*nl.getDen() + nl.getNum();
        int newden= nl.getDen();
        RationalLit * rl = new RationalLit(newnum,newden);
        return rl;

        break;
    }


    }//Fin switch

} //Fin du cas INTLIT
if(classe1==RATIONALLIT){
std::cout<<"cas ratio----------------"<<std::endl;

    switch(classe2){

    case REALLIT :
       {

        const RealLit& nl =dynamic_cast<const RealLit&>(l);
        double val = nl.getValue() + this->getValue();
        // Si la mantisse vaut 0 on cr�e un INTLIT, sinon un REALLIT
        if(val-floor(val)==0){
            std::cout<<"Cree Int"<<std::endl;
            IntLit * it = new IntLit(val);
            return it;
        }
        else{
            RealLit * rl = new RealLit(val);
            return rl;
        }
       }
        break;

   case INTLIT:
    {

        const RationalLit& rl =dynamic_cast<const RationalLit&>(*this);

        double val =l.getValue();
        int newnum = val*rl.getDen() + rl.getNum();
        int newden= rl.getDen();
        RationalLit * rl2 = new RationalLit(newnum,newden);
        return rl2;
    }
        break;


    case RATIONALLIT :
        {
        std::cout<<" cas ration ratio"<<std::endl;
        const RationalLit& rl =dynamic_cast<const RationalLit&>(*this);
        const RationalLit& rll =dynamic_cast<const RationalLit&>(l);

        int newnum = rll.getNum()*rl.getDen() + rl.getNum()*rll.getDen();
        int newden= rl.getDen()*rll.getDen();

        RationalLit * rl2 = new RationalLit(newnum,newden);
        return rl2;
        }
        break;

    }//Fin du switch
}
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
