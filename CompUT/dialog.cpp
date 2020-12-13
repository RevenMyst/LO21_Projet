#include "dialog.h"
#include "ui_dialog.h"
#include <QSignalMapper>
#include <iostream>
#include <QDebug>
#include <QKeyEvent>
#include <sstream>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


    //ui->tableWidget->verticalHeader()->setStyleSheet("::section{background :#45727c;color:white;border:none;text-align:center;padding:5px;}");
    //ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i = 0;i<5;i++){
        QString str;
        str.setNum(4-i);
        str.append(" >> 'TEST'");
        ui->listWidget->addItem(str);
    }
    ui->listWidget->scrollToBottom();



    connect(ui->DelButton,SIGNAL(clicked()),this,SLOT(delChar()));
    connect(ui->SpaceButton,SIGNAL(clicked()),this,SLOT(spaceChar()));
    connect(ui->ClearButton,SIGNAL(clicked()),this,SLOT(clearChar()));

    for(QObject*  o : ui->tabOpe->children()){

     if(o->metaObject()->className()==ui->UNDObutton->metaObject()->className()){
           connect(o,SIGNAL(clicked()),this,SLOT(pushCommandLine()));
        }
    }
    for(QObject*  o : ui->tabAlpha->children()){

     if(o->metaObject()->className()==ui->UNDObutton->metaObject()->className()){
           connect(o,SIGNAL(clicked()),this,SLOT(pushCommandLine()));
        }
    }

}
void Dialog::keyPressEvent ( QKeyEvent * e )
{
    if(ui->tabWidget->currentIndex()==0)
    if(e->key() == Qt::Key_Backspace){
       delChar();
    }else if(e->key() == Qt::Key_Return || e->key() == Qt::Key_Enter){
         ui->commandLine->setText(ui->commandLine->text()+"test");
    }else if(progDeepness == 0 && (e->key() == Qt::Key_Plus||e->key() == Qt::Key_Minus||e->key() == Qt::Key_Asterisk||e->key() == Qt::Key_Slash)){
        ui->commandLine->setText(ui->commandLine->text()+"test");
    }
    else if(e->key() == Qt::Key_BracketLeft){
        progDeepness++;
    }
    else if(e->key() == Qt::Key_BracketLeft && progDeepness > 0){
       progDeepness--;
    }
    else{
      ui->commandLine->setText(ui->commandLine->text()+e->key());
    }


}
void Dialog::pushCommandLine(){
    QPushButton *button = (QPushButton *)sender();
    ui->commandLine->setText(ui->commandLine->text()+button->text());
}

void Dialog::spaceChar(){
    ui->commandLine->setText(ui->commandLine->text()+" ");
}
void Dialog::clearChar(){
    ui->commandLine->setText("");
}
void Dialog::delChar(){
    QString str = ui->commandLine->text();
    str.chop(1);
    ui->commandLine->setText(str);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_checkBox_stateChanged(int arg)
{

    ui->tabOpeAlpha->setVisible(!arg);

}

void Dialog::on_checkBox_2_stateChanged(int arg)
{

    ui->atomKeyboard->setVisible(!arg);

}


void Dialog::on_EnterButton_clicked()
{
    ui->errorLine->setVisible(true);
    ui->closeErrorLine->setVisible(true);

}

void Dialog::on_closeErrorLine_clicked()
{
    ui->errorLine->setVisible(false);
    ui->closeErrorLine->setVisible(false);
}



void Dialog::on_btn0_clicked()
{
    QPushButton* btn = new QPushButton();
    btn->setText("NouveauBouton");
    ui->scrollVar1->layout()->addWidget(btn);

}

void Dialog::on_spinBox_textChanged(const QString &arg1)
{

}
