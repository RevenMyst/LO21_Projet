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
}

int main() {
	afficherPile();
	try {

		OpeDUP* o = new OpeDUP();
		o->exec();
	}
	catch (exception& e) {
		std::cout << e.what() << endl;
	}
	afficherPile();

	
	
	return 0;
}