/****************************************************************************
** Meta object code from reading C++ file 'huarongdaolevelselectwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../huarongdaolevelselectwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'huarongdaolevelselectwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_huarongdaolevelselectwidget_t {
    const uint offsetsAndSize[8];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_huarongdaolevelselectwidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_huarongdaolevelselectwidget_t qt_meta_stringdata_huarongdaolevelselectwidget = {
    {
QT_MOC_LITERAL(0, 27), // "huarongdaolevelselectwidget"
QT_MOC_LITERAL(28, 16), // "SltButtonClicked"
QT_MOC_LITERAL(45, 0), // ""
QT_MOC_LITERAL(46, 5) // "index"

    },
    "huarongdaolevelselectwidget\0"
    "SltButtonClicked\0\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_huarongdaolevelselectwidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void huarongdaolevelselectwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<huarongdaolevelselectwidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SltButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject huarongdaolevelselectwidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_huarongdaolevelselectwidget.offsetsAndSize,
    qt_meta_data_huarongdaolevelselectwidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_huarongdaolevelselectwidget_t
, QtPrivate::TypeAndForceComplete<huarongdaolevelselectwidget, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *huarongdaolevelselectwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *huarongdaolevelselectwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_huarongdaolevelselectwidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int huarongdaolevelselectwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
