#include "QtFunction.hpp"


QtFunction::QtFunction(QObject *parent) : QObject(parent) { }

Q_INVOKABLE quint16 QtFunction::getSpeed()
{
    return speed;
}

Q_INVOKABLE quint16 QtFunction::getRPM()
{
    return rpm;
}

Q_INVOKABLE quint16 QtFunction::getBattery()
{
    return battery;
}

Q_INVOKABLE quint16 QtFunction::getGear()
{
    return gear;
}

Q_INVOKABLE quint16 QtFunction::getDirection()
{
    return direction;
}

