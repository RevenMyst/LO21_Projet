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
int operator-(Litteral& l1, Litteral& l2) {
	return 0;
}
int operator-(IntLit& l1, IntLit& l2) {
	return l1.getValue()-l2.getValue();
}

int main() {
	NumLit* numLit;
//    numLit= new IntLit(4);
    numLit = new RealLit(3.5);
//    numLit = new RationalLit(4,6);
    numLit->exec();
	afficherPile();
	std::cout << "Operator SQRT" << endl;
	Operator* o = new OpeSQRT();
	o->exec();
	afficherPile();
    std::cout << "Operator SQRT" << endl;
    Operator* o1 = new OpeSQRT();
    o1->exec();
    afficherPile();

	return 0;
}