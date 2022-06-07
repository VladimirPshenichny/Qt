/****************************************************************************
** Meta object code from reading C++ file 'myBMP.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Coursework/myBMP.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myBMP.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyImage_t {
    const uint offsetsAndSize[48];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MyImage_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MyImage_t qt_meta_stringdata_MyImage = {
    {
QT_MOC_LITERAL(0, 7), // "MyImage"
QT_MOC_LITERAL(8, 9), // "loadimage"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 11), // "const char*"
QT_MOC_LITERAL(31, 8), // "fileName"
QT_MOC_LITERAL(40, 9), // "imageinfo"
QT_MOC_LITERAL(50, 10), // "resetimage"
QT_MOC_LITERAL(61, 9), // "inversion"
QT_MOC_LITERAL(71, 2), // "lx"
QT_MOC_LITERAL(74, 2), // "ly"
QT_MOC_LITERAL(77, 2), // "rx"
QT_MOC_LITERAL(80, 2), // "ry"
QT_MOC_LITERAL(83, 10), // "monochrome"
QT_MOC_LITERAL(94, 8), // "increase"
QT_MOC_LITERAL(103, 7), // "QColor*"
QT_MOC_LITERAL(111, 5), // "color"
QT_MOC_LITERAL(117, 5), // "point"
QT_MOC_LITERAL(123, 8), // "decrease"
QT_MOC_LITERAL(132, 4), // "line"
QT_MOC_LITERAL(137, 2), // "sx"
QT_MOC_LITERAL(140, 2), // "sy"
QT_MOC_LITERAL(143, 2), // "ex"
QT_MOC_LITERAL(146, 2), // "ey"
QT_MOC_LITERAL(149, 5) // "width"

    },
    "MyImage\0loadimage\0\0const char*\0fileName\0"
    "imageinfo\0resetimage\0inversion\0lx\0ly\0"
    "rx\0ry\0monochrome\0increase\0QColor*\0"
    "color\0point\0decrease\0line\0sx\0sy\0ex\0"
    "ey\0width"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyImage[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x0a,    1 /* Public */,
       5,    0,   65,    2, 0x0a,    3 /* Public */,
       6,    1,   66,    2, 0x0a,    4 /* Public */,
       7,    4,   69,    2, 0x0a,    6 /* Public */,
      12,    4,   78,    2, 0x0a,   11 /* Public */,
      13,    2,   87,    2, 0x0a,   16 /* Public */,
      17,    1,   92,    2, 0x0a,   19 /* Public */,
      18,    6,   95,    2, 0x0a,   21 /* Public */,

 // slots: parameters
    QMetaType::Int, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   10,   11,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Int,   15,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 14,   19,   20,   21,   22,   23,   15,

       0        // eod
};

void MyImage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyImage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->loadimage((*reinterpret_cast< std::add_pointer_t<const char*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->imageinfo(); break;
        case 2: _t->resetimage((*reinterpret_cast< std::add_pointer_t<const char*>>(_a[1]))); break;
        case 3: _t->inversion((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 4: _t->monochrome((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 5: _t->increase((*reinterpret_cast< std::add_pointer_t<QColor*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: _t->decrease((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->line((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QColor*>>(_a[6]))); break;
        default: ;
        }
    }
}

const QMetaObject MyImage::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MyImage.offsetsAndSize,
    qt_meta_data_MyImage,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MyImage_t
, QtPrivate::TypeAndForceComplete<MyImage, std::true_type>
, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QColor *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QColor *, std::false_type>


>,
    nullptr
} };


const QMetaObject *MyImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyImage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyImage.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MyImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
