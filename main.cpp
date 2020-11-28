#include <iostream>
#include "Master.h";
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
	
	RealLit* l1 = new RealLit(5.0);

	std::cout << l1->toString() << endl;

	l1->exec();

	afficherPile();
	
	
	return 0;
}