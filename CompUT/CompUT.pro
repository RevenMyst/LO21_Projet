QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Action.cpp \
    Computer.cpp \
    LitFactory.cpp \
    Litteral.cpp \
    OpeFactory.cpp \
    Operand.cpp \
    Operator.cpp \
    Pile.cpp \
    main.cpp \
    dialog.cpp

HEADERS += \
    Action.h \
    Computer.h \
    ComputerException.h \
    LitFactory.h \
    Litteral.h \
    Master.h \
    OpeFactory.h \
    Operand.h \
    Operator.h \
    Pile.h \
    Visitor.h \
    dialog.h

FORMS += \
    dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
