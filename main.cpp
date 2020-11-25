#include <iostream>
#include "Operator.h"

void afficherPile() {
	std::cout << "==========PILE==========" << std::endl;
	for (size_t i = 0; i < Computer::getInstance().getPile()->size(); i++) {
		std::cout << Computer::getInstance().getPile()->size()-i-1 << ": " << Computer::getInstance().getPile()->getLitterals()[i]->toString() << std::endl;
	}
	std::cout << "========================" << std::endl;
}

int main() {

	IntLit* l1 = new IntLit(50);
	l1->exec();
	IntLit* l2 = new IntLit(5);
	l2->exec();

	afficherPile();

	OpeDUP* o = new OpeDUP;
	o->exec();

	afficherPile();
	
	return 0;
}