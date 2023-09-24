/****************************************************************************
** Meta object code from reading C++ file 'CarInformation.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../CarInformation.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CarInformation.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CarInformation_t {
    QByteArrayData data[15];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CarInformation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CarInformation_t qt_meta_stringdata_CarInformation = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CarInformation"
QT_MOC_LITERAL(1, 15, 11), // "setSpeedRPM"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "_sensorRPM"
QT_MOC_LITERAL(4, 39, 10), // "setBattery"
QT_MOC_LITERAL(5, 50, 8), // "_battery"
QT_MOC_LITERAL(6, 59, 7), // "setGear"
QT_MOC_LITERAL(7, 67, 5), // "_gear"
QT_MOC_LITERAL(8, 73, 12), // "setDirection"
QT_MOC_LITERAL(9, 86, 10), // "_direction"
QT_MOC_LITERAL(10, 97, 8), // "getSpeed"
QT_MOC_LITERAL(11, 106, 6), // "getRPM"
QT_MOC_LITERAL(12, 113, 10), // "getBattery"
QT_MOC_LITERAL(13, 124, 7), // "getGear"
QT_MOC_LITERAL(14, 132, 12) // "getDirection"

    },
    "CarInformation\0setSpeedRPM\0\0_sensorRPM\0"
    "setBattery\0_battery\0setGear\0_gear\0"
    "setDirection\0_direction\0getSpeed\0"
    "getRPM\0getBattery\0getGear\0getDirection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CarInformation[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    1,   62,    2, 0x0a /* Public */,
       6,    1,   65,    2, 0x0a /* Public */,
       8,    1,   68,    2, 0x0a /* Public */,
      10,    0,   71,    2, 0x0a /* Public */,
      11,    0,   72,    2, 0x0a /* Public */,
      12,    0,   73,    2, 0x0a /* Public */,
      13,    0,   74,    2, 0x0a /* Public */,
      14,    0,   75,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QString, QMetaType::UShort,    3,
    QMetaType::QString, QMetaType::UShort,    5,
    QMetaType::QString, QMetaType::UShort,    7,
    QMetaType::QString, QMetaType::UShort,    9,
    QMetaType::UShort,
    QMetaType::UShort,
    QMetaType::UShort,
    QMetaType::UShort,
    QMetaType::UShort,

       0        // eod
};

void CarInformation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CarInformation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->setSpeedRPM((*reinterpret_cast< quint16(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->setBattery((*reinterpret_cast< quint16(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->setGear((*reinterpret_cast< quint16(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->setDirection((*reinterpret_cast< quint16(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { quint16 _r = _t->getSpeed();
            if (_a[0]) *reinterpret_cast< quint16*>(_a[0]) = std::move(_r); }  break;
        case 5: { quint16 _r = _t->getRPM();
            if (_a[0]) *reinterpret_cast< quint16*>(_a[0]) = std::move(_r); }  break;
        case 6: { quint16 _r = _t->getBattery();
            if (_a[0]) *reinterpret_cast< quint16*>(_a[0]) = std::move(_r); }  break;
        case 7: { quint16 _r = _t->getGear();
            if (_a[0]) *reinterpret_cast< quint16*>(_a[0]) = std::move(_r); }  break;
        case 8: { quint16 _r = _t->getDirection();
            if (_a[0]) *reinterpret_cast< quint16*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CarInformation::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CarInformation.data,
    qt_meta_data_CarInformation,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CarInformation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CarInformation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CarInformation.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CarInformation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
