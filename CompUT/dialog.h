#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSignalMapper>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void keyPressEvent ( QKeyEvent * e );

    ~Dialog();
public slots:

    void pushCommandLine();
    void spaceChar();
    void delChar();
    void clearChar();

private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);




    void on_EnterButton_clicked();

    void on_closeErrorLine_clicked();


    void on_btn0_clicked();

    void on_spinBox_textChanged(const QString &arg1);

private:
    unsigned int progDeepness = 0;
    Ui::Dialog *ui;
    QSignalMapper* signalMapper;
};

#endif // DIALOG_H
