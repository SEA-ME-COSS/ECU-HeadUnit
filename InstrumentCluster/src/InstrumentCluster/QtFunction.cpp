#include "QtFunction.hpp"
#include <iostream>

QtFunction::QtFunction(QObject *parent) : QObject(parent) { }

Q_INVOKABLE quint16 QtFunction::getSpeed()
{
    std::cout<<speed<<std::endl;
    return speed;
}

Q_INVOKABLE quint16 QtFunction::getRPM()
{
    std::cout<<rpm<<std::endl;
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

