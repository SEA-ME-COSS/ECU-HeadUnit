#ifndef CARINFORMATION_HPP
#define CARINFORMATION_HPP

#include <QObject>
#include "InstrumentClusterStubImpl.hpp"


class CarInformation : public QObject, public InstrumentClusterStubImpl
{
    Q_OBJECT

public:
    explicit CarInformation(QObject *parent = nullptr);

public Q_SLOTS:
    Q_INVOKABLE quint16 getQSpeed();
    Q_INVOKABLE quint16 getQRPM();
    Q_INVOKABLE quint16 getQBattery();
    Q_INVOKABLE quint16 getQGear();
    Q_INVOKABLE quint16 getQDirection();
};


#endif

