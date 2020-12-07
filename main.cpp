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
	

	/*RationalLit* int1 = new RationalLit(3,2);
	Computer::getInstance().save();
	int1->exec();
	RationalLit* int2 = new RationalLit(5, 2);
	Computer::getInstance().save();
	int2->exec();
	RationalLit* int3 = new RationalLit(7, 2);
	Computer::getInstance().save();
	int3->exec();
	OpeNEG* o = new OpeNEG();
	Computer::getInstance().save();
	o->exec();
	afficherPile();
	Computer::getInstance().save();
	OpeUNDO* o2 = new OpeUNDO();
	o2->exec();
	afficherPile();
	Computer::getInstance().save();
	OpeUNDO* o3 = new OpeUNDO();
	o3->exec();*/
	try {
		std::string command = "[ 'TEUB' DUP ] 'TEST' SWAP DUP EVAL";
		Computer::getInstance().execCommand(command);
		afficherPile();
		command = "UNDO";
		Computer::getInstance().execCommand(command);
		afficherPile();

	}
	catch (exception& e) {
		std::cout << e.what();
	}
		
	
	return 0;
}