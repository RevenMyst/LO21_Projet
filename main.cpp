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
	RealLit* l1 = new RealLit(5.3);
	RationalLit* l2 = new RationalLit(4,7);
	l2->exec();
	l1->exec();
	afficherPile();
	OpePlus* o = new OpePlus();
	o->exec();
	afficherPile();

	
	return 0;
}
