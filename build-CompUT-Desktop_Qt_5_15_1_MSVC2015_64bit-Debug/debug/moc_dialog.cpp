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
    QByteArrayData data[23];
    char stringdata0[301];
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
QT_MOC_LITERAL(6, 52, 11), // "refreshAtom"
QT_MOC_LITERAL(7, 64, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(8, 89, 4), // "arg1"
QT_MOC_LITERAL(9, 94, 26), // "on_checkBox_2_stateChanged"
QT_MOC_LITERAL(10, 121, 25), // "on_closeErrorLine_clicked"
QT_MOC_LITERAL(11, 147, 22), // "on_spinBox_textChanged"
QT_MOC_LITERAL(12, 170, 7), // "refresh"
QT_MOC_LITERAL(13, 178, 5), // "error"
QT_MOC_LITERAL(14, 184, 11), // "const char*"
QT_MOC_LITERAL(15, 196, 3), // "err"
QT_MOC_LITERAL(16, 200, 11), // "std::string"
QT_MOC_LITERAL(17, 212, 11), // "execCommand"
QT_MOC_LITERAL(18, 224, 7), // "editVar"
QT_MOC_LITERAL(19, 232, 7), // "editFun"
QT_MOC_LITERAL(20, 240, 22), // "on_EnterButton_pressed"
QT_MOC_LITERAL(21, 263, 18), // "on_varSave_pressed"
QT_MOC_LITERAL(22, 282, 18) // "on_funSave_pressed"

    },
    "Dialog\0pushCommandLine\0\0spaceChar\0"
    "delChar\0clearChar\0refreshAtom\0"
    "on_checkBox_stateChanged\0arg1\0"
    "on_checkBox_2_stateChanged\0"
    "on_closeErrorLine_clicked\0"
    "on_spinBox_textChanged\0refresh\0error\0"
    "const char*\0err\0std::string\0execCommand\0"
    "editVar\0editFun\0on_EnterButton_pressed\0"
    "on_varSave_pressed\0on_funSave_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x0a /* Public */,
       3,    0,  100,    2, 0x0a /* Public */,
       4,    0,  101,    2, 0x0a /* Public */,
       5,    0,  102,    2, 0x0a /* Public */,
       6,    0,  103,    2, 0x0a /* Public */,
       7,    1,  104,    2, 0x08 /* Private */,
       9,    1,  107,    2, 0x08 /* Private */,
      10,    0,  110,    2, 0x08 /* Private */,
      11,    1,  111,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    2,  115,    2, 0x08 /* Private */,
      17,    0,  120,    2, 0x08 /* Private */,
      18,    0,  121,    2, 0x08 /* Private */,
      19,    0,  122,    2, 0x08 /* Private */,
      20,    0,  123,    2, 0x08 /* Private */,
      21,    0,  124,    2, 0x08 /* Private */,
      22,    0,  125,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 16,   15,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

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
        case 4: _t->refreshAtom(); break;
        case 5: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_checkBox_2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_closeErrorLine_clicked(); break;
        case 8: _t->on_spinBox_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->refresh(); break;
        case 10: _t->error((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 11: _t->execCommand(); break;
        case 12: _t->editVar(); break;
        case 13: _t->editFun(); break;
        case 14: _t->on_EnterButton_pressed(); break;
        case 15: _t->on_varSave_pressed(); break;
        case 16: _t->on_funSave_pressed(); break;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
