#include <QApplication>
#include<QWidget>
#include<QIcon>
#include "dialog.h"
int main(int argc,char*argv[]) {
    QApplication app(argc, argv);
    Dialog fenetre;
    fenetre.setWindowIcon(QIcon("icon.png"));
    //...
    fenetre.show();
    return app.exec();
}
