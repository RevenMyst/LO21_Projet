#include "Operator.h"
#include "Litteral.h"
#include "ComputerException.h"
#include "Computer.h"
#include "OpeFactory.h"
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
	if (l1->getClass() == EXPLIT && (l2->getClass()== PROGLIT || l2->getClass() == RATIONALLIT || l2->getClass() == INTLIT || l2->getClass() == REALLIT)) {
		ExpLit* lit = dynamic_cast<ExpLit*>(l1);
		if (!OpeFactory::isOpe(lit->getValue())) {
			Computer::getInstance().getAtomManager()->addAtom(lit->getValue(), l2);
			delete lit;
		}else{
			l1->exec();
			l2->exec();
			throw ComputerException("Erreur Un op�rateur utilise deja ce nom");
		}

	}
	else {
		l1->exec();
		l2->exec();
		throw ComputerException("Erreur l'operateur STO doit recevoir une litteral expression et un litteral numerique ou programme.");
	}
}

void OpeEVAL::ope()
{
	Litteral* l = Computer::getInstance().getPile()->pull();

	if (l->getClass() == PROGLIT) {
		ProgLit* lit = dynamic_cast<ProgLit*>(l);
		for (Operand* o : lit->getOperands()) {
			o->clone()->exec();
		}
		delete lit;

	}else
	if (l->getClass() == EXPLIT) {
		ExpLit* lit = dynamic_cast<ExpLit*>(l);
		Litteral* atom = Computer::getInstance().getAtomManager()->getLitteral(lit->getValue());
		if (atom) {
			if (atom->getClass() == PROGLIT) {
				ProgLit* plit = dynamic_cast<ProgLit*>(atom);
				for (Operand* o : plit->getOperands()) {
					o->clone()->exec();
				}
				delete plit;
			}
			else {
				atom->exec();
			}
		}
		else {
			l->exec();
			throw ComputerException("Erreur cet expression ne correspond a aucun programme ou variable");
		}
	}
	else {
		l->exec();
		throw ComputerException("Erreur l'operateur EVAL doit recevoir une litteral expression ou programme.");
	}
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
	Litteral* l = Computer::getInstance().getPile()->pull();
	if (l->getClass() == EXPLIT) {
		ExpLit* lit = dynamic_cast<ExpLit*>(l);
		if (!Computer::getInstance().getAtomManager()->removeAtom(lit->getValue())) {
			throw ComputerException("Aucune variable ou programme n'est associ� a cette expression");
		}
		delete l;
	}
	else {
		l->exec();
		throw ComputerException("Erreur, l'op�rateur forget doit s'appliquer sur une litterale expression");
	}
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
