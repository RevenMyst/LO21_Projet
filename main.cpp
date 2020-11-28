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
	IntLit* l1 = new IntLit(50);
	l1->exec();
	IntLit* l2 = new IntLit(5);
	l2->exec();

    //Test d'addition
    //double d = 0.666666666666666666;
    //std::cout<<d<<" "<<1/3<<std::endl;

    RationalLit* r2= new RationalLit(1,2);
	IntLit* r1 = new IntLit(2);

    r2->exec();
    afficherPile();

    r1->exec();
    afficherPile();

    std::cout<<"1"<<endl;
    OpePlus * p = new OpePlus();
    p->exec();
    afficherPile();



	OpeSWAP* o = new OpeSWAP;
	o->exec();

	afficherPile();

	OpeCLEAR* op = new OpeCLEAR;
	op->exec();

	afficherPile();


	return 0;
}
