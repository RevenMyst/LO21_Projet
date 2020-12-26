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
        void keyPressEvent(QKeyEvent * e);
        ~Dialog();

    public slots:

        void pushCommandLine();
        void spaceChar();
        void delChar();
        void clearChar();
        void refreshAtom();

    private slots:
        void on_checkBox_stateChanged(int arg1);
        void on_checkBox_2_stateChanged(int arg1);
        void on_closeErrorLine_clicked();
        void on_spinBox_textChanged(const QString & arg1);
        void refresh();
        void error(const char * err, std::string);
        void execCommand();
        void editVar();
        void editFun();
        void on_EnterButton_pressed();
        void on_varSave_pressed();
        void on_funSave_pressed();

        void on_funSuppr_clicked();

        void on_varSuppr_clicked();

private:
        Computer * computer;
        unsigned int progDeepness = 0;
        Ui::Dialog * ui;
        QSignalMapper * signalMapper;
};

#endif // DIALOG_H
