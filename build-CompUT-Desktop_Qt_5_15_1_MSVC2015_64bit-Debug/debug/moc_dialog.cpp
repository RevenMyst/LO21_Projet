/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CompUT/dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_t {
    QByteArrayData data[13];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Dialog"
QT_MOC_LITERAL(1, 7, 15), // "pushCommandLine"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "spaceChar"
QT_MOC_LITERAL(4, 34, 7), // "delChar"
QT_MOC_LITERAL(5, 42, 9), // "clearChar"
QT_MOC_LITERAL(6, 52, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(7, 77, 4), // "arg1"
QT_MOC_LITERAL(8, 82, 26), // "on_checkBox_2_stateChanged"
QT_MOC_LITERAL(9, 109, 22), // "on_EnterButton_clicked"
QT_MOC_LITERAL(10, 132, 25), // "on_closeErrorLine_clicked"
QT_MOC_LITERAL(11, 158, 15), // "on_btn0_clicked"
QT_MOC_LITERAL(12, 174, 22) // "on_spinBox_textChanged"

    },
    "Dialog\0pushCommandLine\0\0spaceChar\0"
    "delChar\0clearChar\0on_checkBox_stateChanged\0"
    "arg1\0on_checkBox_2_stateChanged\0"
    "on_EnterButton_clicked\0on_closeErrorLine_clicked\0"
    "on_btn0_clicked\0on_spinBox_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    1,   68,    2, 0x08 /* Private */,
       8,    1,   71,    2, 0x08 /* Private */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    1,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pushCommandLine(); break;
        case 1: _t->spaceChar(); break;
        case 2: _t->delChar(); break;
        case 3: _t->clearChar(); break;
        case 4: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_checkBox_2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_EnterButton_clicked(); break;
        case 7: _t->on_closeErrorLine_clicked(); break;
        case 8: _t->on_btn0_clicked(); break;
        case 9: _t->on_spinBox_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Dialog.data,
    qt_meta_data_Dialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
