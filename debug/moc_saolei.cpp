/****************************************************************************
** Meta object code from reading C++ file 'saolei.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../saolei.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'saolei.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_saolei_t {
    const uint offsetsAndSize[16];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_saolei_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_saolei_t qt_meta_stringdata_saolei = {
    {
QT_MOC_LITERAL(0, 6), // "saolei"
QT_MOC_LITERAL(7, 12), // "slot_newGame"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 15), // "slot_level_easy"
QT_MOC_LITERAL(37, 17), // "slot_level_normal"
QT_MOC_LITERAL(55, 15), // "slot_level_hard"
QT_MOC_LITERAL(71, 15), // "slot_level_self"
QT_MOC_LITERAL(87, 19) // "slot_level_self_get"

    },
    "saolei\0slot_newGame\0\0slot_level_easy\0"
    "slot_level_normal\0slot_level_hard\0"
    "slot_level_self\0slot_level_self_get"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_saolei[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x0a,    1 /* Public */,
       3,    0,   51,    2, 0x0a,    2 /* Public */,
       4,    0,   52,    2, 0x0a,    3 /* Public */,
       5,    0,   53,    2, 0x0a,    4 /* Public */,
       6,    0,   54,    2, 0x0a,    5 /* Public */,
       7,    0,   55,    2, 0x0a,    6 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void saolei::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<saolei *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slot_newGame(); break;
        case 1: _t->slot_level_easy(); break;
        case 2: _t->slot_level_normal(); break;
        case 3: _t->slot_level_hard(); break;
        case 4: _t->slot_level_self(); break;
        case 5: _t->slot_level_self_get(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject saolei::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_saolei.offsetsAndSize,
    qt_meta_data_saolei,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_saolei_t
, QtPrivate::TypeAndForceComplete<saolei, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *saolei::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *saolei::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_saolei.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int saolei::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
