/****************************************************************************
** Meta object code from reading C++ file 'increase.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Coursework/increase.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'increase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_increase_t {
    const uint offsetsAndSize[22];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_increase_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_increase_t qt_meta_stringdata_increase = {
    {
QT_MOC_LITERAL(0, 8), // "increase"
QT_MOC_LITERAL(9, 11), // "do_increase"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 7), // "QColor*"
QT_MOC_LITERAL(30, 9), // "set_color"
QT_MOC_LITERAL(40, 13), // "make_increase"
QT_MOC_LITERAL(54, 6), // "centre"
QT_MOC_LITERAL(61, 6), // "leftup"
QT_MOC_LITERAL(68, 8), // "leftdown"
QT_MOC_LITERAL(77, 7), // "rightup"
QT_MOC_LITERAL(85, 9) // "rightdown"

    },
    "increase\0do_increase\0\0QColor*\0set_color\0"
    "make_increase\0centre\0leftup\0leftdown\0"
    "rightup\0rightdown"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_increase[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   67,    2, 0x0a,    4 /* Public */,
       5,    0,   68,    2, 0x0a,    5 /* Public */,
       6,    0,   69,    2, 0x0a,    6 /* Public */,
       7,    0,   70,    2, 0x0a,    7 /* Public */,
       8,    0,   71,    2, 0x0a,    8 /* Public */,
       9,    0,   72,    2, 0x0a,    9 /* Public */,
      10,    0,   73,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void increase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<increase *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->do_increase((*reinterpret_cast< std::add_pointer_t<QColor*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->set_color(); break;
        case 2: _t->make_increase(); break;
        case 3: _t->centre(); break;
        case 4: _t->leftup(); break;
        case 5: _t->leftdown(); break;
        case 6: _t->rightup(); break;
        case 7: _t->rightdown(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (increase::*)(QColor * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&increase::do_increase)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject increase::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_increase.offsetsAndSize,
    qt_meta_data_increase,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_increase_t
, QtPrivate::TypeAndForceComplete<increase, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QColor *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *increase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *increase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_increase.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int increase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void increase::do_increase(QColor * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
