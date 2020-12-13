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



    IntLit * a = new IntLit(25);
    IntLit * b = new IntLit(5);
    a->exec();
    afficherPile();
    b->exec();
    afficherPile();

    OpeDivision * o = new OpeDivision();
    o->exec();
    afficherPile();


	return 0;
}
