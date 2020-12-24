#include "Litteral.h"
#include <sstream>
#include<iostream>
#include "Visitor.h"
#include "Computer.h"
#include<QFont>
#include<QFontMetrics>

std::string Litteral::toPileString(){
    return reduceString();
}
std::string Litteral::reduceString(){
    string str = toString();
    bool reduced = false;
    while(QFontMetrics(QFont("Segoe UI",15)).horizontalAdvance(str.c_str())>320){
        str = str.substr(0, str.size()-1);
        reduced = true;
    }
    if(reduced){
        str+="...";
    }
    return str;
}
void Litteral::exec()
{
    Computer::getInstance().getPile()->push(this);
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


void RationalLit::accept(Visitor* visitor)
{
	visitor->visitRationalLit(this);
}

void RationalLit::ReductionRational() {
	for (int i = numerateur * denominateur; i > 1; i--) {
		if ((denominateur % i == 0) && (numerateur % i == 0)) {
            std::cout<<i<<" "<<denominateur % i<<" "<<numerateur % i<<endl;
			denominateur /= i;
			numerateur /= i;
		}
	}
}
void RationalLit::exec()
{
    if(denominateur == 1){
        Computer::getInstance().getPile()->push(new IntLit(numerateur));
        delete this;
    }else if(numerateur == 0){
        Computer::getInstance().getPile()->push(new IntLit(0));
        delete this;
    }else{
        Computer::getInstance().getPile()->push(this);
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

void ProgLit::compile()
{
	for (Operand* o : getOperands()) {
		o->clone()->exec();
	}
	delete this;
}

void ProgLit::accept(Visitor* visitor)
{
	visitor->visitProgLit(this);
}

std::string ProgLit::toPileString(){
    if(QFontMetrics(QFont("Segoe UI",15)).horizontalAdvance(toString().c_str())>320){
      return reduceString()+"]";
    }else{
        return toString();
    }
}

/*******************************/
/************EXPLIT*************/
/*******************************/
void ExpLit::accept(Visitor* visitor)
{
	visitor->visitExpLit(this);
}
void ExpLit::compile()
{
    const std::string s = getValue();
    Litteral* l1;
    l1 = Computer::getInstance().getAtomManager()->getLitteral(s);
    if(l1!=nullptr) {
        Operand* l2;
        if(l1->getClass()== PROGLIT) {
            l2 = l1->clone();
            ProgLit* plit = dynamic_cast<ProgLit*>(l2);
            plit->compile();
        }
        else {
            l2 = l1->clone();
            l2->exec();
        }
    }
    else {
        throw ComputerException("Erreur l'expression ne correspond a aucun programme ou variable");
    }
    delete this;
}

std::string ExpLit::toPileString(){

    if(QFontMetrics(QFont("Segoe UI",15)).horizontalAdvance(toString().c_str())>320){
      return reduceString()+"'";
    }else{
        return toString();
    }

}

/*******************************/
/************INTLIT*************/
/*******************************/

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
