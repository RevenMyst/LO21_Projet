#include <iostream>
#include "Master.h"
void afficherPile() {
	std::cout << "==========PILE==========" << std::endl;
	int i = 0;
	for (Litteral* l : Computer::getInstance().getPile()->getLitterals()) {
		std::cout << i << ": " << l->toString() << std::endl;
		i++;
	}
	std::cout << "========================" << std::endl;
	std::cout<<std::endl;
}
int operator-(Litteral& l1, Litteral& l2) {
	return 0;
}
int operator-(IntLit& l1, IntLit& l2) {
	return l1.getValue()-l2.getValue();
}
int main() {
	IntLit* l1 = new IntLit(50);
	l1->exec();

    RationalLit* r2= new RationalLit(5,3);
	IntLit* l2 = new IntLit(1);
	RationalLit* r1 = new RationalLit(1,3);
    RealLit * r3 = new RealLit(0.1);

    r3->exec();
    afficherPile();
    r2->exec();
    afficherPile();

    OpePlus * p = new OpePlus();
    p->exec();
    afficherPile();



	OpeSWAP* o = new OpeSWAP;
	o->exec();

	afficherPile();

	OpeCLEAR* op = new OpeCLEAR;
	op->exec();

	afficherPile();


	

	RationalLit* int1 = new RationalLit(3,2);
	int1->exec();
	afficherPile();
	std::cout << "Operator NEG" << endl;
	OpeNEG* o = new OpeNEG();
	o->exec();
	afficherPile();
	std::cout << "Operator NOT" << endl;
	OpeNOT* o2 = new OpeNOT();
	o2->exec();
	afficherPile();
	std::cout << "Operator NOT" << endl;
	OpeNOT* o3 = new OpeNOT();
	o3->exec();
	afficherPile();
	
	return 0;
}
