#include <iostream>
#include "Master.h"
#include <QApplication>
#include<QWidget>
#include<QIcon>
#include "interface.h"
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

int main(int argc,char*argv[]) {
    QApplication app(argc, argv);
    Interface fenetre;
    fenetre.setWindowIcon(QIcon("icon.png"));
    //...
    fenetre.show();
    return app.exec();
}



