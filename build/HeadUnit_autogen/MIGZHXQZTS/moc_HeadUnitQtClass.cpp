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
    QByteArrayData data[17];
    char stringdata0[200];
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
QT_MOC_LITERAL(3, 34, 11), // "gearChanged"
QT_MOC_LITERAL(4, 46, 16), // "directionChanged"
QT_MOC_LITERAL(5, 63, 12), // "lightChanged"
QT_MOC_LITERAL(6, 76, 17), // "setIPCManagerGear"
QT_MOC_LITERAL(7, 94, 5), // "_gear"
QT_MOC_LITERAL(8, 100, 22), // "setIPCManagerDirection"
QT_MOC_LITERAL(9, 123, 10), // "_direction"
QT_MOC_LITERAL(10, 134, 18), // "setIPCManagerLight"
QT_MOC_LITERAL(11, 153, 6), // "_light"
QT_MOC_LITERAL(12, 160, 8), // "poweroff"
QT_MOC_LITERAL(13, 169, 9), // "sensorRpm"
QT_MOC_LITERAL(14, 179, 4), // "gear"
QT_MOC_LITERAL(15, 184, 9), // "direction"
QT_MOC_LITERAL(16, 194, 5) // "light"

    },
    "HeadUnitQtClass\0sensorRpmChanged\0\0"
    "gearChanged\0directionChanged\0lightChanged\0"
    "setIPCManagerGear\0_gear\0setIPCManagerDirection\0"
    "_direction\0setIPCManagerLight\0_light\0"
    "poweroff\0sensorRpm\0gear\0direction\0"
    "light"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HeadUnitQtClass[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       4,   68, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   58,    2, 0x0a /* Public */,
       8,    1,   61,    2, 0x0a /* Public */,
      10,    1,   64,    2, 0x0a /* Public */,
      12,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::UShort,    7,
    QMetaType::Void, QMetaType::UShort,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

 // properties: name, type, flags
      13, QMetaType::UShort, 0x00495103,
      14, QMetaType::UShort, 0x00495103,
      15, QMetaType::UShort, 0x00495103,
      16, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void HeadUnitQtClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HeadUnitQtClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sensorRpmChanged(); break;
        case 1: _t->gearChanged(); break;
        case 2: _t->directionChanged(); break;
        case 3: _t->lightChanged(); break;
        case 4: _t->setIPCManagerGear((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 5: _t->setIPCManagerDirection((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 6: _t->setIPCManagerLight((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->poweroff(); break;
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
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HeadUnitQtClass::gearChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HeadUnitQtClass::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HeadUnitQtClass::directionChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (HeadUnitQtClass::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HeadUnitQtClass::lightChanged)) {
                *result = 3;
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
        case 1: *reinterpret_cast< quint16*>(_v) = _t->gear(); break;
        case 2: *reinterpret_cast< quint16*>(_v) = _t->direction(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->light(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<HeadUnitQtClass *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSensorRpm(*reinterpret_cast< quint16*>(_v)); break;
        case 1: _t->setGear(*reinterpret_cast< quint16*>(_v)); break;
        case 2: _t->setDirection(*reinterpret_cast< quint16*>(_v)); break;
        case 3: _t->setLight(*reinterpret_cast< QString*>(_v)); break;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
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
void HeadUnitQtClass::gearChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void HeadUnitQtClass::directionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void HeadUnitQtClass::lightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
