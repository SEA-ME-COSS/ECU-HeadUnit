#include "QtFunction.hpp"


QtFunction::QtFunction(QObject *parent) : QObject(parent) { }

Q_INVOKABLE void QtFunction::setGear(quint16 _gear)
{
    sender.IPCManagerTargetProxy->setGearMode(_gear, sender.callStatus, sender.returnMessage);
    
    return;
}

Q_INVOKABLE void QtFunction::setDirection(quint16 _direction)
{
    sender.IPCManagerTargetProxy->setDirection(_direction, sender.callStatus, sender.returnMessage);
    
    return;
}

Q_INVOKABLE quint16 QtFunction::getSensorRpm()
{
    return sensorRpm;
}

