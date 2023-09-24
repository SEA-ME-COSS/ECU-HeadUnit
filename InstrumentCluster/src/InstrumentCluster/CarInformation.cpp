#include "CarInformation.hpp"

CarInformation::CarInformation(QObject *parent) : QObject(parent)
{
    speed = 50;
    rpm = 50;
    battery = 50;
    gear = 1;
    direction = 1;
}

QString CarInformation::setSpeedRPM(quint16 _sensorRPM)
{
    rpm = (quint16)((qreal)_sensorRPM / 2.6);
    speed = (quint16)((qreal)rpm * 3.4);
    return ":)";
}

QString CarInformation::setBattery(quint16 _battery)
{
    battery = _battery;
    return ":)";
}

QString CarInformation::setGear(quint16 _gear)
{
    gear = _gear;
    return ":)";
}

QString CarInformation::setDirection(quint16 _direction)
{
    direction = _direction;
    return ":)";
}

Q_INVOKABLE quint16 CarInformation::getSpeed()
{
    return speed;
}

Q_INVOKABLE quint16 CarInformation::getRPM()
{
    return rpm;
}

Q_INVOKABLE quint16 CarInformation::getBattery()
{
    return battery;
}

Q_INVOKABLE quint16 CarInformation::getGear()
{
    return gear;
}

Q_INVOKABLE quint16 CarInformation::getDirection()
{
    return direction;
}

