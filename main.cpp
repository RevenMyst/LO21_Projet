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


	try {
		std::string command = "25";
		Computer::getInstance().execCommand(command);
		afficherPile();
		command = "DEN";
		Computer::getInstance().execCommand(command);
		afficherPile();

	}
	catch (exception& e) {
		std::cout << e.what();
	}





	return 0;
}