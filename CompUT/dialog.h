//////////////////////////////////////////////////////////////////////////////////////////////
/// <summary> Definit l'interface graphique et le lie avec le moteur computer </summary>
///
/// <classes> Dialog </classes>
///
///////////////////////////////////////////////////////////////////////////////////////////////
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSignalMapper>
#include "Computer.h"

namespace Ui {
    class Dialog;
}

class Dialog: public QDialog {
    Q_OBJECT

    public:

        explicit Dialog(QWidget * parent = nullptr);
        // lorsque l'utilisateur tape dans la ligne de commande
        void keyPressEvent(QKeyEvent * e);
        ~Dialog();


    private slots:
        //ajouter le string du bouton au clic
        void pushCommandLine();
        // ajout espace
        void spaceChar();
        // suppression
        void delChar();
        //vide la command line
        void clearChar();
        //maj affichage des var et fonctions
        void refreshAtom();
        //afficher/masquer claviers
        void on_checkBox_stateChanged(int arg1);
        void on_checkBox_2_stateChanged(int arg1);
        //fermer la ligne d'erreur
        void on_closeErrorLine_clicked();
        //afficher + ou - d'elements de la pile
        void on_spinBox_textChanged(const QString & arg1);
        // maj de l'affichage de la pile
        void refresh();
        //affichage erreur
        void error(const char * err, std::string);
        //recupere commande et execute
        void execCommand();
        // ecriture des infos d'une variable pour maj
        void editVar();
        // ecriture des infos d'une fonction pour maj
        void editFun();
        //detection clic bouton entré
        void on_EnterButton_pressed();
        //maj/ajout variable
        void on_varSave_pressed();
        //maj/ajout fonction
        void on_funSave_pressed();
        //suppresion fonction
        void on_funSuppr_clicked();
        //suppression variable
        void on_varSuppr_clicked();

private:
        Computer * computer;
        unsigned int progDeepness = 0;
        Ui::Dialog * ui;
        QSignalMapper * signalMapper;
};

#endif // DIALOG_H
