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

int main() {

	IntLit* a = new IntLit(5);
	RealLit* b = new RealLit(5.3);
	RationalLit* c = new RationalLit(2,5);

    IntLit* d = new IntLit(8);
	RealLit* e = new RealLit(3.8);
	RationalLit*f = new RationalLit(6,7);

	c->exec();
	f->exec();
	afficherPile();
	OpeDivision* o = new OpeDivision();
	o->exec();
	afficherPile();


	return 0;
}
