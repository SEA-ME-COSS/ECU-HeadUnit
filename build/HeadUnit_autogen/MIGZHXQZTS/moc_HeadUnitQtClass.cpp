/****************************************************************************
** Meta object code from reading C++ file 'HeadUnitQtClass.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/HeadUnit/HeadUnitQtClass.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HeadUnitQtClass.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HeadUnitQtClass_t {
    QByteArrayData data[13];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HeadUnitQtClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HeadUnitQtClass_t qt_meta_stringdata_HeadUnitQtClass = {
    {
QT_MOC_LITERAL(0, 0, 15), // "HeadUnitQtClass"
QT_MOC_LITERAL(1, 16, 16), // "sensorRpmChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 15), // "steeringChanged"
QT_MOC_LITERAL(4, 50, 7), // "setGear"
QT_MOC_LITERAL(5, 58, 5), // "_gear"
QT_MOC_LITERAL(6, 64, 12), // "setDirection"
QT_MOC_LITERAL(7, 77, 10), // "_direction"
QT_MOC_LITERAL(8, 88, 8), // "setLight"
QT_MOC_LITERAL(9, 97, 6), // "_light"
QT_MOC_LITERAL(10, 104, 8), // "poweroff"
QT_MOC_LITERAL(11, 113, 9), // "sensorRpm"
QT_MOC_LITERAL(12, 123, 8) // "steering"

    },
    "HeadUnitQtClass\0sensorRpmChanged\0\0"
    "steeringChanged\0setGear\0_gear\0"
    "setDirection\0_direction\0setLight\0"
    "_light\0poweroff\0sensorRpm\0steering"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HeadUnitQtClass[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       2,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   46,    2, 0x0a /* Public */,
       6,    1,   49,    2, 0x0a /* Public */,
       8,    1,   52,    2, 0x0a /* Public */,
      10,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::UShort,    5,
    QMetaType::Void, QMetaType::UShort,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,

 // properties: name, type, flags
      11, QMetaType::UShort, 0x00495103,
      12, QMetaType::UShort, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void HeadUnitQtClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HeadUnitQtClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sensorRpmChanged(); break;
        case 1: _t->steeringChanged(); break;
        case 2: _t->setGear((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 3: _t->setDirection((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 4: _t->setLight((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->poweroff(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HeadUnitQtClass::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HeadUnitQtClass::sensorRpmChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HeadUnitQtClass::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HeadUnitQtClass::steeringChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<HeadUnitQtClass *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< quint16*>(_v) = _t->sensorRpm(); break;
        case 1: *reinterpret_cast< quint16*>(_v) = _t->steering(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<HeadUnitQtClass *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSensorRpm(*reinterpret_cast< quint16*>(_v)); break;
        case 1: _t->setSteering(*reinterpret_cast< quint16*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject HeadUnitQtClass::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_HeadUnitQtClass.data,
    qt_meta_data_HeadUnitQtClass,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HeadUnitQtClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HeadUnitQtClass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HeadUnitQtClass.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HeadUnitQtClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void HeadUnitQtClass::sensorRpmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void HeadUnitQtClass::steeringChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
