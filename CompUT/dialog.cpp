#include "dialog.h"
#include "ui_dialog.h"
#include <QSignalMapper>
#include <iostream>
#include <QDebug>
#include <QKeyEvent>
#include <sstream>
#include "Litteral.h"


Dialog::Dialog(QWidget * parent):
    QDialog(parent),
    computer( & Computer::getInstance()),
    ui(new Ui::Dialog) {
        ui -> setupUi(this);

        //enleve le focus auto des boutons sinon clic si space enfoncé
        for (QPushButton * btns: ui -> tabWidget -> findChildren < QPushButton * > ()) {
            btns -> setFocusPolicy(Qt::NoFocus);
        }
        ui -> commandLine -> setFocusPolicy(Qt::NoFocus);

        //efface le message d'erreur
        on_closeErrorLine_clicked();

        //lie les 3 btn espace suppr et effacer a leur slots
        connect(ui -> DelButton, SIGNAL(clicked()), this, SLOT(delChar()));
        connect(ui -> SpaceButton, SIGNAL(clicked()), this, SLOT(spaceChar()));
        connect(ui -> ClearButton, SIGNAL(clicked()), this, SLOT(clearChar()));

        //connecte les boutons du clavier pour imprimer leur texte dans la commandLine au clic
        for (QObject * o: ui -> tabOpe -> children()) {

            if (o -> metaObject() -> className() == ui -> UNDObutton -> metaObject() -> className()) {
                connect(o, SIGNAL(clicked()), this, SLOT(pushCommandLine()));
            }
        }
        for (QObject * o: ui -> tabAlpha -> children()) {

            if (o -> metaObject() -> className() == ui -> UNDObutton -> metaObject() -> className()) {
                connect(o, SIGNAL(clicked()), this, SLOT(pushCommandLine()));
            }
        }

        //connexion des signals du computer au slot du dialog
        connect(computer, SIGNAL(modifEtat()), this, SLOT(refresh()));
        connect(computer, SIGNAL(modifAtom()), this, SLOT(refreshAtom()));
        connect(computer, SIGNAL(error(const char * , std::string)), this, SLOT(error(const char * , std::string)));

    }
void Dialog::refresh() {
    //Supprime la list et reaffiche la pile
    ui -> listWidget -> clear();
    std::string str;
    unsigned int indice = 1;
    for (Litteral * lit: computer -> getPile() -> getLitterals()) {
        if (indice <= computer -> getPile() -> toShow()) {
            //std::cout<<QFontMetrics(ui->listWidget->font()).horizontalAdvance(lit->toPileString().c_str())<<endl;
            str = "[" + to_string(indice) + "] >> " + lit -> toPileString().c_str();
            ui -> listWidget -> addItem(QString::fromUtf8(str.c_str()));
        }
        indice++;
    }
}
void Dialog::refreshAtom() {
    //suppression des anciens boutons
    for (QObject * o: ui -> scrollVar1 -> children()) {
        if (o -> metaObject() -> className() == ui -> UNDObutton -> metaObject() -> className()) {

            o -> deleteLater();
        }
    }
    for (QObject * o: ui -> scrollFun1 -> children()) {
        if (o -> metaObject() -> className() == ui -> UNDObutton -> metaObject() -> className()) {

            o -> deleteLater();
        }
    }
    for (QObject * o: ui -> scrollVar2 -> children()) {
        if (o -> metaObject() -> className() == ui -> UNDObutton -> metaObject() -> className()) {

            o -> deleteLater();
        }
    }
    for (QObject * o: ui -> scrollFun2 -> children()) {
        if (o -> metaObject() -> className() == ui -> UNDObutton -> metaObject() -> className()) {

            o -> deleteLater();
        }
    }
    //creation nouveau boutons
    for (std::pair < std::string, Litteral * > pair: computer -> getAtomManager() -> getAtoms()) {

        QPushButton * btn = new QPushButton();
        connect(btn, SIGNAL(clicked()), this, SLOT(pushCommandLine()));
        btn -> setText(QString::fromUtf8(pair.first.c_str()));

        QPushButton * btn2 = new QPushButton();

        btn2 -> setText(QString::fromUtf8(pair.first.c_str()));

        btn -> setFocusPolicy(Qt::NoFocus);
        btn2 -> setFocusPolicy(Qt::NoFocus);

        //ajout du bouton dans le scrollArea correspondant
        if (pair.second -> getClass() == PROGLIT) {
            ui -> scrollFun1 -> layout() -> addWidget(btn);
            connect(btn2, SIGNAL(clicked()), this, SLOT(editFun()));
            ui -> scrollFun2 -> layout() -> addWidget(btn2);
        } else {
            ui -> scrollVar1 -> layout() -> addWidget(btn);
            connect(btn2, SIGNAL(clicked()), this, SLOT(editVar()));
            ui -> scrollVar2 -> layout() -> addWidget(btn2);
        }
    }

}

void Dialog::editVar() {
    // reecris les informations de l'Atom dans l'interface pour l'editer
    QString str = static_cast < QPushButton * > (sender()) -> text();
    ui -> varName -> setText(str);
    std::string value = computer -> getAtomManager() -> getLitteral(str.toStdString()) -> toString();
    ui -> varValue -> setText(QString::fromUtf8(value.c_str()));
}
void Dialog::editFun() {
    // reecris les informations de l'Atom dans l'interface pour l'editer
    QString str = static_cast < QPushButton * > (sender()) -> text();
    ui -> funName -> setText(str);
    std::string value = computer -> getAtomManager() -> getLitteral(str.toStdString()) -> toString();
    ui -> funValue -> setText(QString::fromUtf8(value.c_str()));
}
void Dialog::error(const char * err, std::string str) {
    // Lors d'unne erreur, affiche la barre d'erreur avec les message
    ui -> errorLine -> setText(err);
    ui -> errorLine -> setVisible(true);
    ui -> closeErrorLine -> setVisible(true);
    // on remet dans commandLine le reste de la command qui na pas pu etre executé
    ui -> commandLine -> setText(QString::fromStdString(str));

}
void Dialog::execCommand() {
    //on recupere la commande
    QString command = ui -> commandLine -> text();
    ui -> commandLine -> setText("");
    //on execute
    computer -> execCommand(command.toStdString());
}
void Dialog::keyPressEvent(QKeyEvent * e) {
    // les detections de clic ne doivent se faire que sur la tab de la calculatrice, pas dans les parametres
    if (ui -> tabWidget -> currentIndex() == 0) {

        if (e -> key() == Qt::Key_Backspace) {
            delChar();
        } else if (e -> key() == Qt::Key_Return || e -> key() == Qt::Key_Enter) {
            execCommand();
        } else if (progDeepness == 0 && (e -> key() == Qt::Key_Plus || e -> key() == Qt::Key_Minus || e -> key() == Qt::Key_Asterisk || e -> key() == Qt::Key_Slash)) {
            // si l'utilisateur n'est pas en train d'ecrire un programme et quil appui sur + - * / -> execute la command
            if (ui -> commandLine -> text().size() == 0 || ui -> commandLine -> text()[ui -> commandLine -> text().size() - 1] != " ") {
                // on ajoute un espace si l'utilisateur la oublié
                ui -> commandLine -> setText(ui -> commandLine -> text() + " ");
            }
            ui -> commandLine -> setText(ui -> commandLine -> text() + e -> key());
            execCommand();
        } else if (e -> key() == Qt::Key_ParenLeft || e -> key() == Qt::Key_BracketLeft) {
            // a chaque [ on augmente la profondeur pour savoir quand l'utilisateur est en train d'ecrire un programme ou non
            progDeepness++;
            ui -> commandLine -> setText(ui -> commandLine -> text() + "[");
        } else if ((e -> key() == Qt::Key_ParenRight || e -> key() == Qt::Key_BracketRight) && progDeepness > 0) {
            // on decremente a chaque ]
            progDeepness--;
            ui -> commandLine -> setText(ui -> commandLine -> text() + "]");
        } else if (e -> key() != Qt::Key_AltGr && e -> key() != Qt::Key_Alt && e -> key() != Qt::Key_Control && e -> key() != Qt::Key_Shift) {
            // on ignore Altgr Shift Alt et Ctrl qui cree des pb de prises de commande
            ui -> commandLine -> setText(ui -> commandLine -> text() + e -> key());
        }

    }
}
void Dialog::pushCommandLine() {
    // on ajoute dans commandLine le texte du bouton cliqué
    QPushButton * button = (QPushButton * ) sender();
    ui -> commandLine -> setText(ui -> commandLine -> text() + button -> text());
}

void Dialog::spaceChar() {
    // on ajoute un espace
    ui -> commandLine -> setText(ui -> commandLine -> text() + " ");
}
void Dialog::clearChar() {
    //on vide la commandLine
    ui -> commandLine -> setText("");
}
void Dialog::delChar() {
    // on supprime le dernier caractere
    QString str = ui -> commandLine -> text();
    str.chop(1);
    ui -> commandLine -> setText(str);
}

Dialog::~Dialog() {
    delete ui;
}
// pour activer et desactiver les claviers
void Dialog::on_checkBox_stateChanged(int arg) {

    ui -> tabOpeAlpha -> setVisible(!arg);

}

void Dialog::on_checkBox_2_stateChanged(int arg) {

    ui -> atomKeyboard -> setVisible(!arg);

}

void Dialog::on_EnterButton_pressed() {
    execCommand();
}
//pour fermer la banderole d'erreur
void Dialog::on_closeErrorLine_clicked() {
    ui -> errorLine -> setVisible(false);
    ui -> closeErrorLine -> setVisible(false);
}

// pour augmenter la taille de la pile affichée
void Dialog::on_spinBox_textChanged(const QString & arg1) {
    computer -> getPile() -> toShow() = arg1.toInt();
    refresh();
}

// sauvegarde d'un Atom
void Dialog::on_varSave_pressed() {
    QString varName = ui -> varName -> text();
    QString varValue = ui -> varValue -> text();
    ui -> varName -> setText("");
    ui -> varValue -> setText("");
    try {
        Operand * o = computer -> createOperand(varValue.toStdString());
        // En soit l'utilisateur peut creer une fonction dans le champs variable
        if (dynamic_cast < Litteral * > (o)) {
            computer ->save();
            computer -> getAtomManager() -> addAtom(varName.toStdString(), dynamic_cast < Litteral * > (o));
        }

    } catch (exception & e) {
        error(e.what(), "");
    }

}

void Dialog::on_funSave_pressed() {
    QString funName = ui -> funName -> text();
    QString funValue = ui -> funValue -> text();
    ui -> funName -> setText("");
    ui -> funValue -> setText("");
    try {
        Operand * o = computer -> createOperand(funValue.toStdString());
        ///ici l'utilisateur ne peut que creer un programme
        if (dynamic_cast < ProgLit * > (o)) {
            computer -> save();
            computer -> getAtomManager() -> addAtom(funName.toStdString(), dynamic_cast < ProgLit * > (o));
        } else {
            throw ComputerException("Erreur : la valeur ne correspond pas a un programme");
        }
    } catch (exception & e) {
        error(e.what(), "");
    }
}

void Dialog::on_funSuppr_clicked()
{
    QString funName = ui -> funName -> text();
    ui -> funName -> setText("");
    ui -> funValue -> setText("");
    computer->getAtomManager()->removeAtom(funName.toStdString());
}

void Dialog::on_varSuppr_clicked()
{
    QString varName = ui -> varName -> text();
    ui -> varName -> setText("");
    ui -> varValue -> setText("");
    computer->getAtomManager()->removeAtom(varName.toStdString());
}
