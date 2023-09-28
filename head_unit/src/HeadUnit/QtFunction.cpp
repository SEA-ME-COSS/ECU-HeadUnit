#include "QtFunction.hpp"


QtFunction::QtFunction(QObject *parent) : QObject(parent) { }

Q_INVOKABLE void QtFunction::setGear(quint16 _gear)
{
    gear = _gear;
    
    return;
}

Q_INVOKABLE void QtFunction::setDirection(quint16 _direction)
{
    direction = _direction;
    
    return;
}

Q_INVOKABLE quint16 QtFunction::getSensorRpm()
{
    return sensorRpm;
}

