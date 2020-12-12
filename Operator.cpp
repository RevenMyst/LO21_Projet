#include "Operator.h"
#include "Litteral.h"
#include "ComputerException.h"
#include "Computer.h"
#include "OpeFactory.h"
#include "Action.h"
#include <iostream>

void OpeDUP::ope()
{
	Litteral* l = Computer::getInstance().getPile()->pull();
	Computer::getInstance().getPile()->push(l);
	Computer::getInstance().getPile()->push(dynamic_cast<Litteral*>(l->clone()));

}

void OpeDROP::ope()
{
	delete Computer::getInstance().getPile()->pull();
}

void OpeCLEAR::ope()
{
	size_t size = Computer::getInstance().getPile()->size();
	for (size_t i = 0; i < size; i++) {
		delete Computer::getInstance().getPile()->pull();
	}
}

void OpeSWAP::ope()
{
	Litteral* l1 = Computer::getInstance().getPile()->pull();
	Litteral* l2 = Computer::getInstance().getPile()->pull();
	Computer::getInstance().getPile()->push(l1);
	Computer::getInstance().getPile()->push(l2);
}

bool Operator::verify()
{
	return (arite <= Computer::getInstance().getPile()->size());
}

void Operator::exec()
{
	if (verify()) {
		ope();
		delete this;
	}
	else {
		throw ComputerException("Erreur : Il n'y a pas assez de Litterals dans la pile.");
	}
}

void OpeSTO::ope()
{
	Pile* p = Computer::getInstance().getPile();
	Litteral* l1 = p->pull();
	Litteral* l2 = p->pull();
	if (l1->getClass() == EXPLIT && l2->getClass()!= EXPLIT) {
		ExpLit* lit = dynamic_cast<ExpLit*>(l1);
		if (!OpeFactory::isOpe(lit->getValue())) {
			//si ce n'est pas un nom reservé
			Computer::getInstance().getAtomManager()->addAtom(lit->getValue(), l2);
			delete lit;
		}else{
			l1->exec();
			l2->exec();
			throw ComputerException("Erreur Un operateur utilise deja ce nom");
		}

	}
	else {
		l1->exec();
		l2->exec();
		throw ComputerException("Erreur l'operateur STO doit recevoir une litteral expression et une litteral numerique ou programme.");
	}
}

void OpeEVAL::ope()
{
	Litteral* l = Computer::getInstance().getPile()->pull();
	l->accept(this);
}

void OpeEVAL::visitExpLit(ExpLit* l)
{
	Litteral* lit = Computer::getInstance().getAtomManager()->getLitteral(l->getValue());
	if (lit->getClass() == PROGLIT) {
		dynamic_cast<ProgLit*>(lit)->compile();
	}
	else {
		lit->exec();
		delete lit;
	}
}

void OpeEVAL::visitProgLit(ProgLit* l)
{
	l->compile();
}

void OpeAND::ope()
{
    Litteral* l1 = Computer::getInstance().getPile()->pull();
	Litteral* l2 = Computer::getInstance().getPile()->pull();
	if((l1->getClass() == INTLIT && dynamic_cast<IntLit*>(l1)->getInt() == 0) || (l2->getClass() == INTLIT && dynamic_cast<IntLit*>(l2)->getInt() == 0)) {
        Litteral* l3 = new IntLit(0);
        l3->exec();
	}
    else {
        Litteral* l3 = new IntLit(1);
        l3->exec();
    }
    delete l1;
    delete l2;
}

void OpeOR::ope()
{
    Litteral* l1 = Computer::getInstance().getPile()->pull();
	Litteral* l2 = Computer::getInstance().getPile()->pull();
	if((l1->getClass() == INTLIT && dynamic_cast<IntLit*>(l1)->getInt() == 0) && (l2->getClass() == INTLIT && dynamic_cast<IntLit*>(l2)->getInt() == 0)) {
        Litteral* l3 = new IntLit(0);
        l3->exec();
	}
    else {
        Litteral* l3 = new IntLit(1);
        l3->exec();
    }
    delete l1;
    delete l2;
}

void OpeDIV::ope()
{
    Litteral* l1 = Computer::getInstance().getPile()->pull();
	Litteral* l2 = Computer::getInstance().getPile()->pull();
	if(l1->getClass() == INTLIT && l2->getClass() == INTLIT) {
        int divid = dynamic_cast<IntLit*>(l2)->getInt();
        int divis = dynamic_cast<IntLit*>(l1)->getInt();
        Litteral* l3 = new IntLit(divid/divis);
        delete l1;
        delete l2;
        l3->exec();
	}
	else {
        l2->exec();
        l1->exec();
        throw ComputerException("Erreur l'operateur DIV doit recevoir des litterales entieres");
	}
}

void OpeMOD::ope()
{
    Litteral* l1 = Computer::getInstance().getPile()->pull();
	Litteral* l2 = Computer::getInstance().getPile()->pull();
	if(l1->getClass() == INTLIT && l2->getClass() == INTLIT) {
        int divid = dynamic_cast<IntLit*>(l2)->getInt();
        int divis = dynamic_cast<IntLit*>(l1)->getInt();
        Litteral* l3 = new IntLit(divid%divis);
        delete l1;
        delete l2;
        l3->exec();
	}
	else {
        l2->exec();
        l1->exec();
        throw ComputerException("Erreur l'operateur MOD doit recevoir des litterales entieres");
	}
}

void OpeFORGET::ope()
{
	Computer::getInstance().getPile()->pull()->accept(this);
}
void OpeFORGET::visitExpLit(ExpLit* l)
{
	if (!Computer::getInstance().getAtomManager()->removeAtom(l->getValue())) {
		throw ComputerException("Aucune variable ou programme n'est associ� a cette expression");
	}
	delete l;
}
void OpeEQUAL::ope()
{
	Pile* p = Computer::getInstance().getPile();
	Litteral* l1 = p->pull();
	Litteral* l2 = p->pull();
	if (*l2 == *l1) {
		p->push(new IntLit(1));
	}
	else {
		p->push(new IntLit(0));
	}
	delete l1;
	delete l2;
}

void OpeLTE::ope()
{
	Pile* p = Computer::getInstance().getPile();
	Litteral* l1 = p->pull();
	Litteral* l2 = p->pull();
	if (*l2 <= *l1) {
		p->push(new IntLit(1));
	}
	else {
		p->push(new IntLit(0));
	}
	delete l1;
	delete l2;
}

void OpeGTE::ope()
{
	Pile* p = Computer::getInstance().getPile();
	Litteral* l1 = p->pull();
	Litteral* l2 = p->pull();
	if (*l2 >= *l1) {
		p->push(new IntLit(1));
	}
	else {
		p->push(new IntLit(0));
	}
	delete l1;
	delete l2;
}

void OpeGT::ope()
{
	Pile* p = Computer::getInstance().getPile();
	Litteral* l1 = p->pull();
	Litteral* l2 = p->pull();
	if (*l2 > *l1) {
		p->push(new IntLit(1));
	}
	else {
		p->push(new IntLit(0));
	}
	delete l1;
	delete l2;
}


void OpePlus::ope()
{
    Litteral* l1 = Computer::getInstance().getPile()->pull();
	Litteral* l2 = Computer::getInstance().getPile()->pull();
	tuple<string, LitType, LitType> t = make_tuple(this->toString(), l1->getClass(), l2->getClass());
	if (Action::exist(t)) {
		Action::getActions().at(t)->exec(l1, l2)->exec();
	}
	else {
		// l'addition est commutative, pour limiter le nombre d'action on verifie si l'addition dans l'autre sens existe
		get<1>(t) = l2->getClass();
		get<2>(t) = l1->getClass();
		if (Action::exist(t)) {
			Action::getActions().at(t)->exec(l2, l1)->exec();
		}
		else {
			//ces deux litterales ne possedent pas d'actions pour les additionner on reempile et on envoie une erreur
			l2->exec();
			l1->exec();
			throw ComputerException("Erreur : ces deux litterales ne peuvent etre additionnées");

		}
	}

}

void OpeMul::ope()
{
    Litteral* l1 = Computer::getInstance().getPile()->pull();
	Litteral* l2 = Computer::getInstance().getPile()->pull();
	tuple<string, LitType, LitType> t = make_tuple(this->toString(), l1->getClass(), l2->getClass());
	if (Action::exist(t)) {
		Action::getActions().at(t)->exec(l1, l2)->exec();
	}
	else {
		// l'addition est commutative, pour limiter le nombre d'action on verifie si la multiplication dans l'autre sens existe
		get<1>(t) = l2->getClass();
		get<2>(t) = l1->getClass();
		if (Action::exist(t)) {
			Action::getActions().at(t)->exec(l2, l1)->exec();
		}
		else {
			//ces deux litterales ne possedent pas d'actions pour les mulitplier on reempile et on envoie une erreur
			l2->exec();
			l1->exec();
			throw ComputerException("Erreur : ces deux litterales ne peuvent etre multipliées");

		}
	}

}

void OpeMoins::ope()
{
    Litteral* l1 = Computer::getInstance().getPile()->pull();
	Litteral* l2 = Computer::getInstance().getPile()->pull();
	tuple<string, LitType, LitType> t = make_tuple(this->toString(), l2->getClass(), l1->getClass());
	if (Action::exist(t)) {
		Action::getActions().at(t)->exec(l2, l1)->exec();
	}

    else {
        //ces deux litterales ne possedent pas d'actions pour les soustraire on reempile et on envoie une erreur
        l2->exec();
        l1->exec();
        throw ComputerException("Erreur : ces deux litterales ne peuvent etre soustraites");

		}
}


void OpeDivision::ope()
{
    Litteral* l1 = Computer::getInstance().getPile()->pull();
	Litteral* l2 = Computer::getInstance().getPile()->pull();

	if(static_cast<IntLit*>(l1)!= nullptr && static_cast<IntLit*>(l1)->getValue()==0)
    {
        l2->exec();
        l1->exec();
        throw ComputerException("On ne peut pas diviser par zero");
    }
    else {
	tuple<string, LitType, LitType> t = make_tuple(this->toString(), l2->getClass(), l1->getClass());
	if (Action::exist(t)) {
		Action::getActions().at(t)->exec(l2, l1)->exec();
	}

    else {
        //ces deux litterales ne possedent pas d'actions pour les soustraire on reempile et on envoie une erreur
        l2->exec();
        l1->exec();
        throw ComputerException("Erreur : ces deux litterales ne peuvent etre divisees");

		}
}
}
void OpeLT::ope()
{
	Pile* p = Computer::getInstance().getPile();
	Litteral* l1 = p->pull();
	Litteral* l2 = p->pull();
	if (*l2 < *l1) {
		p->push(new IntLit(1));
	}
	else {
		p->push(new IntLit(0));
	}
	delete l1;
	delete l2;
}

void OpeDIF::ope()
{
	Pile* p = Computer::getInstance().getPile();
	Litteral* l1 = p->pull();
	Litteral* l2 = p->pull();
	if (*l2 != *l1) {
		p->push(new IntLit(1));
	}
	else {
		p->push(new IntLit(0));
	}
	delete l1;
	delete l2;
}

void OpeNOT::ope()
{
	Litteral* l = Computer::getInstance().getPile()->pull();
	Litteral* tmp;
	if (l->getClass() == INTLIT && dynamic_cast<IntLit*>(l)->getInt() == 0) {
		tmp = new IntLit(1);
	}
	else {
		tmp = new IntLit(0);
	}
	tmp->exec();
	delete l;


}

void OpeNEG::ope()
{
	Litteral* l = Computer::getInstance().getPile()->pull();

	l->accept(this);
	delete l;

}

void OpeNEG::visitIntLit(IntLit* l)
{
	IntLit* lit = new IntLit(-l->getValue());
	lit->exec();
}

void OpeNEG::visitRealLit(RealLit* l)
{
	RealLit* lit = new RealLit(-l->getValue());
	lit->exec();
}

void OpeNEG::visitRationalLit(RationalLit* l)
{

	RationalLit* lit = new RationalLit(-l->getNum(), l->getDen());
	lit->exec();
}


