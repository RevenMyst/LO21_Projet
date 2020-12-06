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
	afficherPile();
	try {

		OpeDUP* o = new OpeDUP();
		o->exec();
	}
	catch (exception& e) {
		std::cout << e.what() << endl;
	}
	afficherPile();

	IntLit* int1 = new IntLit(5);
	IntLit* int2 = new IntLit(2);
	Litteral* lit1 = int1;
	Litteral* lit2 = int2;

	std::cout << *lit1-*lit2 << endl; // ecris 0
	std::cout << *int1-*int2 << endl; // ecris 3
	
	
	return 0;
}