#include <iostream>
#include <math.h>
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

    IntLit * a = new IntLit(9);
    IntLit * b = new IntLit(2);
    RealLit * c = new RealLit(0.3);
    RealLit * d = new RealLit(3.5);
    RationalLit * e = new RationalLit(1,3);
    RationalLit * f = new RationalLit(27,8);

    f->exec();
    afficherPile();
    c->exec();
    afficherPile();

    OpePOW * o = new OpePOW();
    o->exec();
    afficherPile();


	return 0;
}
