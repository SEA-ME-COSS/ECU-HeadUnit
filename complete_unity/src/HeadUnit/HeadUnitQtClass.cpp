#include "HeadUnitQtClass.hpp"


HeadUnitQtClass::HeadUnitQtClass(QObject *parent) : QObject(parent)
{
    QsensorRpm = 0;
}

quint16 HeadUnitQtClass::sensorRpm() const
{
    return QsensorRpm;
}

void HeadUnitQtClass::setSensorRpm(uint16_t _sensorRpm)
{
    QsensorRpm = _sensorRpm;
    emit sensorRpmChanged();
    
    return;
}

Q_INVOKABLE void HeadUnitQtClass::setGear(quint16 _gear)
{
    sender.IPCManagerTargetProxy->setGearMode(_gear, sender.callStatus, sender.returnMessage);
    
    return;
}

Q_INVOKABLE void HeadUnitQtClass::setDirection(quint16 _direction)
{
    sender.IPCManagerTargetProxy->setDirection(_direction, sender.callStatus, sender.returnMessage);
    
    return;
}

Q_INVOKABLE void HeadUnitQtClass::setLight(QString _light)
{    
    sender.IPCManagerTargetProxy->setLight(_light.toStdString(), sender.callStatus, sender.returnMessage);
    
    return;
}

Q_INVOKABLE void HeadUnitQtClass::poweroff()
{
    int exitCode = system("poweroff");
    
    return;
}


HeadUnitQtClass carinfo;

