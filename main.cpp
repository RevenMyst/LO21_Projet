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
    numLit= new IntLit(60);
//    numLit = new RealLit(3.5);
//    numLit = new RationalLit(4,9);
    numLit->exec();
	afficherPile();
	std::cout << "Operator SIN" << endl;
	Operator* o = new OpeSIN();
	o->exec();
	afficherPile();
    std::cout << "Operator COS" << endl;
    Operator* o1 = new OpeCOS();
    o1->exec();
    afficherPile();

    std::cout << "sin:" << std::sin(60) << "... cos:" << std::cos(std::sin(60)) << std::endl;

	return 0;
}