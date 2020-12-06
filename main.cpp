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
	

	IntLit* int1 = new IntLit(5);
	int1->exec();
	afficherPile();
	std::cout << "Operator NEG" << endl;
	OpeNEG* o = new OpeNEG();
	o->exec();
	afficherPile();
	std::cout << "Operator NOT" << endl;
	OpeNOT* o2 = new OpeNOT();
	o2->exec();
	afficherPile();
	std::cout << "Operator NOT" << endl;
	OpeNOT* o3 = new OpeNOT();
	o3->exec();
	afficherPile();
	
	return 0;
}