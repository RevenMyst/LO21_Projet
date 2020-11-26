#include <iostream>
#include "Master.h";
void afficherPile() {
	std::cout << "==========PILE==========" << std::endl;
	int i = 0;
	for (Litteral* l : Computer::getInstance().getPile()->getLitterals()) {
		std::cout << i << ": " << l->toString() << std::endl;
		i++;
	}
	std::cout << "========================" << std::endl;
}

int main() {

	IntLit* l1 = new IntLit(50);
	l1->exec();
	RationalLit* l2 = new RationalLit(5,2);
	l2->exec();
	RealLit* l3 = new RealLit(0.5);
	l3->exec();
	std::cout << l3->toString() <<"~"<<l3->getMant() << std::endl;
	if (*l3 == *l2) {
		std::cout << "true"<< std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}
	
	afficherPile();

	OpeSWAP* o = new OpeSWAP;
	o->exec();

	afficherPile();

	OpeCLEAR* op = new OpeCLEAR;
	op->exec();

	afficherPile();
	
	return 0;
}