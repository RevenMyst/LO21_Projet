#include "Operator.h"
#include "Litteral.h"
#include "ComputerException.h"
#include "Computer.h"
#include "OpeFactory.h"
#include "Action.h"
#include <iostream>
#include <cmath>

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

    try {
        l->compile();
    }
    catch (std::exception const& e) {
        l->exec();
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
        throw ComputerException("Aucune variable ou programme n'est associé a cette expression");
	}
	delete l;
}
void OpeEQUAL::ope()
{
	Pile* p = Computer::getInstance().getPile();
	Litteral* l1 = p->pull();
	Litteral* l2 = p->pull();
    CompLit* lit1 = dynamic_cast<CompLit*>(l1);
    CompLit* lit2 = dynamic_cast<CompLit*>(l2);
	if(lit1 != nullptr && lit2 != nullptr)
	{
            if (lit1->getComparableValue() == lit2->getComparableValue()) {
				p->push(new IntLit(1));
			}
			else {
				p->push(new IntLit(0));
			}
	}else{
			if(l1->toString() == l2->toString()) {
				p->push(new IntLit(1));
			}
			else {
				p->push(new IntLit(0));
			}
	}
	delete l1;
	delete l2;
}

void OpeLTE::ope()
{
	Pile* p = Computer::getInstance().getPile();
	Litteral* l1 = p->pull();
	Litteral* l2 = p->pull();
    CompLit* lit1 = dynamic_cast<CompLit*>(l1);
    CompLit* lit2 = dynamic_cast<CompLit*>(l2);
	if(lit1 != nullptr && lit2 != nullptr)
	{
            if (lit2->getComparableValue() <= lit1->getComparableValue()) {
				p->push(new IntLit(1));
			}
			else {
				p->push(new IntLit(0));
			}
			delete l1;
			delete l2;
	} else {
			l1->exec();
			l2->exec();
			throw ComputerException("Erreur: ces deux litterales ne sont pas comparables");
    }
}

void OpeGTE::ope()
{
	Pile* p = Computer::getInstance().getPile();
	Litteral* l1 = p->pull();
	Litteral* l2 = p->pull();
    CompLit* lit1 = dynamic_cast<CompLit*>(l1);
    CompLit* lit2 = dynamic_cast<CompLit*>(l2);
	if(lit1 != nullptr && lit2 != nullptr)
	{
            if (lit2->getComparableValue() >= lit1->getComparableValue()) {
				p->push(new IntLit(1));
			}
			else {
				p->push(new IntLit(0));
			}
			delete l1;
			delete l2;
	} else {
			l1->exec();
			l2->exec();
			throw ComputerException("Erreur: ces deux litterales ne sont pas comparables");
    }
}

void OpeGT::ope()
{
	Pile* p = Computer::getInstance().getPile();
	Litteral* l1 = p->pull();
	Litteral* l2 = p->pull();
    CompLit* lit1 = dynamic_cast<CompLit*>(l1);
    CompLit* lit2 = dynamic_cast<CompLit*>(l2);
	if(lit1 != nullptr && lit2 != nullptr)
	{
            if (lit2->getComparableValue() > lit1->getComparableValue()) {
				p->push(new IntLit(1));
			}
			else {
				p->push(new IntLit(0));
			}
			delete l1;
			delete l2;
	} else {
			l1->exec();
			l2->exec();
			throw ComputerException("Erreur: ces deux litterales ne sont pas comparables");
    }
}
void OpeLT::ope()
{
	Pile* p = Computer::getInstance().getPile();
	Litteral* l1 = p->pull();
	Litteral* l2 = p->pull();
    CompLit* lit1 = dynamic_cast<CompLit*>(l1);
    CompLit* lit2 = dynamic_cast<CompLit*>(l2);
	if(lit1 != nullptr && lit2 != nullptr)
	{
            if (lit2->getComparableValue() < lit1->getComparableValue()) {
				p->push(new IntLit(1));
			}
			else {
				p->push(new IntLit(0));
			}
			delete l1;
			delete l2;
	} else {
			l1->exec();
			l2->exec();
			throw ComputerException("Erreur: ces deux litterales ne sont pas comparables");
	}
}

void OpeDIF::ope()
{
	Pile* p = Computer::getInstance().getPile();
	Litteral* l1 = p->pull();
	Litteral* l2 = p->pull();
    CompLit* lit1 = dynamic_cast<CompLit*>(l1);
    CompLit* lit2 = dynamic_cast<CompLit*>(l2);
	if(lit1 != nullptr && lit2 != nullptr)
	{
            if (lit1->getComparableValue() != lit2->getComparableValue()) {
				p->push(new IntLit(1));
			}
			else {
				p->push(new IntLit(0));
			}
	}else{
            if(l1->toString() != l2->toString()) {
				p->push(new IntLit(1));
			}
			else {
				p->push(new IntLit(0));
			}
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
		// la mulitplication est commutative, pour limiter le nombre d'action on verifie si la multiplication dans l'autre sens existe
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


void OpeIFT::ope()
{
    Litteral* l1 = Computer::getInstance().getPile()->pull();
	Litteral* l2 = Computer::getInstance().getPile()->pull();
    if(l2->getClass() == PROGLIT) {
        ProgLit* plit = dynamic_cast<ProgLit*>(l2);
        plit->compile();
        l2 = Computer::getInstance().getPile()->pull();
    }
    else if(l2->getClass() == EXPLIT) {
        ExpLit* elit = dynamic_cast<ExpLit*>(l2);
        try {
            elit->compile();
        }
        catch(std::exception const& e) {
            l2->exec();
            l1->exec();
            return;
        }
        l2 = Computer::getInstance().getPile()->pull();
    }
    if(l2->getClass() == INTLIT && dynamic_cast<IntLit*>(l2)->getInt() == 0)
        delete l1;
    else {
        if(l1->getClass() == PROGLIT) {
            ProgLit* plit = dynamic_cast<ProgLit*>(l1);
            plit->compile();
        }
        else if(l1->getClass() == EXPLIT) {
            ExpLit* elit = dynamic_cast<ExpLit*>(l1);
            try {
                elit->compile();
            }
            catch(std::exception const& e) {
                l2->exec();
                l1->exec();
                return;
            }
        }
        else l1->exec();
    }
    delete l2;
}

void OpeIFTE::ope()
{
    Litteral* l3 = Computer::getInstance().getPile()->pull();
    Litteral* l1 = Computer::getInstance().getPile()->pull();
	Litteral* l2 = Computer::getInstance().getPile()->pull();
    if(l2->getClass() == PROGLIT) {
        ProgLit* plit = dynamic_cast<ProgLit*>(l2);
        plit->compile();
        l2 = Computer::getInstance().getPile()->pull();
    }
    else if(l2->getClass() == EXPLIT) {
        ExpLit* elit = dynamic_cast<ExpLit*>(l2);
        try {
            elit->compile();
        }
        catch(std::exception const& e) {
            l2->exec();
            l1->exec();
            l3->exec();
            return;
        }
        l2 = Computer::getInstance().getPile()->pull();
    }
    if(l2->getClass() == INTLIT && dynamic_cast<IntLit*>(l2)->getInt() == 0) {
        if(l3->getClass() == PROGLIT) {
            ProgLit* plit = dynamic_cast<ProgLit*>(l3);
            plit->compile();
        }
        else if(l3->getClass() == EXPLIT) {
            ExpLit* elit = dynamic_cast<ExpLit*>(l3);
            try {
                elit->compile();
            }
            catch(std::exception const& e) {
                l2->exec();
                l1->exec();
                l3->exec();
                return;
            }
        }
        else l3->exec();
        delete l1;
    }
    else {
        if(l1->getClass() == PROGLIT) {
            ProgLit* plit = dynamic_cast<ProgLit*>(l1);
            plit->compile();
        }
        else if(l1->getClass() == EXPLIT) {
            ExpLit* elit = dynamic_cast<ExpLit*>(l1);
            try {
                elit->compile();
            }
            catch(std::exception const& e) {
                l2->exec();
                l1->exec();
                l3->exec();
                return;
            }
        }
        else l1->exec();
        delete l3;
    }
    delete l2;
}

void OpeWHILE::ope()
{
    Litteral* l1 = Computer::getInstance().getPile()->pull();
	Litteral* l2 = Computer::getInstance().getPile()->pull();
    std::cout << "WHILE"<<endl;
	bool stop = false;
	while(stop != true) {
        std::cout << "boucle :"<<endl;
        Litteral* l3 = dynamic_cast<Litteral*>(l1->clone());
        Litteral* l4 = dynamic_cast<Litteral*>(l2->clone());
        if(l4->getClass() == PROGLIT) {
            ProgLit* plit = dynamic_cast<ProgLit*>(l4);
            plit->compile();
            l4 = Computer::getInstance().getPile()->pull();
        }
        else if(l4->getClass() == EXPLIT) {
            ExpLit* elit = dynamic_cast<ExpLit*>(l4);
            try {
                elit->compile();
            }
            catch(std::exception const& e) {
                delete l3;
                delete l4;
                l2->exec();
                l1->exec();
                return;
            }
            l4 = Computer::getInstance().getPile()->pull();
        }
        if(l4->getClass() == INTLIT && dynamic_cast<IntLit*>(l4)->getInt() == 0) {
            std::cout << "STOP"<<endl;
            stop = true;
            delete l1;
            delete l2;
            delete l3;
        }
        else {
            if(l3->getClass() == PROGLIT) {
                ProgLit* plit = dynamic_cast<ProgLit*>(l3);
                plit->compile();
                delete l3;
            }
            else if(l3->getClass() == EXPLIT) {
                ExpLit* elit = dynamic_cast<ExpLit*>(l3);
                try {
                    elit->compile();
                    delete l3;
                }
                catch(std::exception const& e) {
                    delete l3;
                    delete l4;
                    l2->exec();
                    l1->exec();
                    return;
                }
            }
            else l3->exec();
        }
        delete l4;
	}
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
    Litteral *l = Computer::getInstance().getPile()->pull();
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

void OpeNEG::visitRationalLit(RationalLit *l) {
    RationalLit *lit = new RationalLit(-l->getNum(), l->getDen());
    lit->exec();
}

void OpeNUM::ope() {
    Litteral *l = Computer::getInstance().getPile()->pull();
    l->accept(this);
    delete l;
}

void OpeNUM::visitIntLit(IntLit *l) {
    IntLit *lit = dynamic_cast<IntLit *>(l->clone());
    lit->exec();
}

void OpeNUM::visitRationalLit(RationalLit *l) {
    IntLit *lit = new IntLit(l->getNum());
    lit->exec();
}

void OpeDEN::ope() {
    Litteral *l = Computer::getInstance().getPile()->pull();
    l->accept(this);
    delete l;
}

void OpeDEN::visitIntLit(IntLit *l) {
    IntLit *lit = new IntLit(1);
    lit->exec();
}

void OpeDEN::visitRationalLit(RationalLit *l) {
    IntLit *lit = new IntLit(l->getDen());
    lit->exec();
}

void OpePOW::ope(){

    Litteral* l1 = Computer::getInstance().getPile()->pull();
	Litteral* l2 = Computer::getInstance().getPile()->pull();
	tuple<string, LitType, LitType> t = make_tuple(this->toString(), l2->getClass(), l1->getClass());
	if (Action::exist(t)) {
		Action::getActions().at(t)->exec(l2, l1)->exec();
	}

    else {
        //ces deux litterales ne possedent pas d'actions avec une puissance on reempile et on envoie une erreur
        l2->exec();
        l1->exec();
        throw ComputerException("Erreur : ces deux litterales ne peuvent etre mises à la puissance");

		}


}

void OpeEXP::ope() {
		Litteral *l = Computer::getInstance().getPile()->pull();
        std::cout<<"EXP";
		l->accept(this);
		delete l;
}

void OpeEXP::visitIntLit(IntLit *l){
        RealLit *lit = new RealLit(exp(l->getValue()));
		lit->exec();
}

void OpeEXP::visitRationalLit(RationalLit *l){
        RealLit *lit = new RealLit(exp(l->getValue()));
		lit->exec();
}

void OpeEXP::visitRealLit(RealLit *l){
        RealLit *lit = new RealLit(exp(l->getValue()));
		lit->exec();
}


void OpeSQRT::ope() {
    Litteral *l = Computer::getInstance().getPile()->pull();
    l->accept(this);
    delete l;
}

void OpeSQRT::visitIntLit(IntLit *l) {
	if (l->getValue() >= 0) {
		//le reel est automatiquement converti en IntLit si mantisse nulle
		RealLit* lit = new RealLit(std::sqrt(l->getValue()));
		lit->exec();
	}
	else {
		l->exec();
		throw ComputerException("Erreur : racine carrée négative.");
	}

}

void OpeSQRT::visitRealLit(RealLit *l) {
	if (l->getValue() >= 0) {
		//le reel est automatiquement converti en IntLit si mantisse nulle
		RealLit* lit = new RealLit(std::sqrt(l->getValue()));
		lit->exec();
	}
	else {
		l->exec();
		throw ComputerException("Erreur : racine carrée négative.");
	}
}

void OpeSQRT::visitRationalLit(RationalLit *l) {
	if (l->getValue() >= 0) {
        Litteral* lit;
		double sqrtNum = std::sqrt(l->getNum());
		double sqrtDen = std::sqrt(l->getDen());
		if (sqrtNum - static_cast<int>(sqrtNum) == 0 && sqrtDen - static_cast<int>(sqrtDen) == 0) {
			lit = new RationalLit(static_cast<int>(sqrtNum), static_cast<int>(sqrtDen));
		}
		else {
			double res = sqrtNum / sqrtDen;
			lit = new RealLit(res);
		}
		lit->exec();
	}
	else {
		l->exec();
		throw ComputerException("Erreur : racine carrée négative.");
	}
}

void OpeTrigonometry::ope() {
    Litteral *l = Computer::getInstance().getPile()->pull();
    l->accept(this);
    delete l;
}

void OpeTrigonometry::pushValue(double x) {
    RealLit *lit = new RealLit(x);
    lit->exec();
}

void OpeTrigonometry::visitIntLit(IntLit *l1) {
    pushValue(getResult(l1->getValue()));
}

void OpeTrigonometry::visitRealLit(RealLit *l1) {
    pushValue(getResult(l1->getValue()));
}

void OpeTrigonometry::visitRationalLit(RationalLit *l1) {
    pushValue(getResult(l1->getValue()));
}


void OpeUNDO::ope()
{
	Computer::getInstance().backup();
}


void AtomLit::ope()
{
	const std::string s = getValue();
	ExpLit* exp = new ExpLit(s);
	try {
		exp->compile();
	}
	catch (std::exception const& e) {
        exp->exec();
    }
}
