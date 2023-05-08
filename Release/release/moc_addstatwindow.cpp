/****************************************************************************
** Meta object code from reading C++ file 'addstatwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../plateforme-de-jdr/ui/addstatwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addstatwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_addstatwindow_t {
    uint offsetsAndSizes[18];
    char stringdata0[14];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[13];
    char stringdata5[6];
    char stringdata6[11];
    char stringdata7[13];
    char stringdata8[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_addstatwindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_addstatwindow_t qt_meta_stringdata_addstatwindow = {
    {
        QT_MOC_LITERAL(0, 13),  // "addstatwindow"
        QT_MOC_LITERAL(14, 16),  // "onAddStatClicked"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 16),  // "onDelStatClicked"
        QT_MOC_LITERAL(49, 12),  // "leaveAndSave"
        QT_MOC_LITERAL(62, 5),  // "leave"
        QT_MOC_LITERAL(68, 10),  // "closeEvent"
        QT_MOC_LITERAL(79, 12),  // "QCloseEvent*"
        QT_MOC_LITERAL(92, 5)   // "event"
    },
    "addstatwindow",
    "onAddStatClicked",
    "",
    "onDelStatClicked",
    "leaveAndSave",
    "leave",
    "closeEvent",
    "QCloseEvent*",
    "event"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_addstatwindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    1,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject addstatwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_addstatwindow.offsetsAndSizes,
    qt_meta_data_addstatwindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_addstatwindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<addstatwindow, std::true_type>,
        // method 'onAddStatClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDelStatClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'leaveAndSave'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'leave'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'closeEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QCloseEvent *, std::false_type>
    >,
    nullptr
} };

void addstatwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<addstatwindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onAddStatClicked(); break;
        case 1: _t->onDelStatClicked(); break;
        case 2: _t->leaveAndSave(); break;
        case 3: _t->leave(); break;
        case 4: _t->closeEvent((*reinterpret_cast< std::add_pointer_t<QCloseEvent*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *addstatwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addstatwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_addstatwindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int addstatwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
