#include "HeadUnitQtClass.hpp"

HeadUnitQtClass::HeadUnitQtClass(QObject *parent) : QObject(parent)
{
    QsensorRpm = 0;
}

quint16 HeadUnitQtClass::sensorRpm() const
{
    return QsensorRpm;
}

quint16 HeadUnitQtClass::direction() const
{
    return Qdirection;
}

void HeadUnitQtClass::setSensorRpm(uint16_t _sensorRpm)
{
    QsensorRpm = _sensorRpm;
    emit sensorRpmChanged();
}

void HeadUnitQtClass::setDirection(uint16_t _direction)
{
    Qdirection = _direction;
    emit directionChanged();
}

Q_INVOKABLE void HeadUnitQtClass::poweroff()
{
    int exitCode = system("sudo poweroff");
}

HeadUnitQtClass carinfo;
