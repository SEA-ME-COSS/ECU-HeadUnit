#include "CarInformation.hpp"


CarInformation::CarInformation(QObject *parent) : QObject(parent) { }

Q_INVOKABLE quint16 CarInformation::getQSpeed()
{
    return getSpeed();
}

Q_INVOKABLE quint16 CarInformation::getQRPM()
{
    return getRPM();
}

Q_INVOKABLE quint16 CarInformation::getQBattery()
{
    return getBattery();
}

Q_INVOKABLE quint16 CarInformation::getQGear()
{
    return getGear();
}

Q_INVOKABLE quint16 CarInformation::getQDirection()
{
    return getDirection();
}

