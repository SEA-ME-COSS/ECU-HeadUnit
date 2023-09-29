#include "QtManagerClass.hpp"


QtManagerClass::QtManagerClass(QObject *parent) : QObject(parent)
{
    QsensorRpm = 0;
}

quint16 QtManagerClass::sensorRpm() const
{
    return QsensorRpm;
}

void QtManagerClass::setSensorRpm(uint16_t _sensorRpm)
{
    QsensorRpm = _sensorRpm;
    emit sensorRpmChanged();
}

Q_INVOKABLE void QtManagerClass::setGear(quint16 _gear)
{
    sender.IPCManagerTargetProxy->setGearMode(_gear, sender.callStatus, sender.returnMessage);
    
    return;
}

Q_INVOKABLE void QtManagerClass::setDirection(quint16 _direction)
{
    sender.IPCManagerTargetProxy->setDirection(_direction, sender.callStatus, sender.returnMessage);
    
    return;
}


QtManagerClass carinfo;

