#include "HeadUnitQtClass.hpp"
#include <unistd.h>

// Constructor for HeadUnitQtClass
HeadUnitQtClass::HeadUnitQtClass(QObject *parent) : QObject(parent)
{
    // Initialize sensorRpm and steering to 0
    QsensorRpm = 0;
    Qsteering = 0;
}

// Getter for sensorRpm
quint16 HeadUnitQtClass::sensorRpm() const
{
    return QsensorRpm;
}

// Getter for steering
quint16 HeadUnitQtClass::steering() const
{
    return Qsteering;
}

// Setter for sensorRpm
void HeadUnitQtClass::setSensorRpm(uint16_t _sensorRpm)
{
    QsensorRpm = _sensorRpm;
    // Emit the signal to notify changes to QML
    emit sensorRpmChanged();
}

// Setter for steering
void HeadUnitQtClass::setSteering(uint16_t _steering)
{
    Qsteering = _steering;
    // Emit the signal to notify changes to QML
    emit steeringChanged();
}

// QML-invokable method to set the gear using IPCManagerTargetProxy
Q_INVOKABLE void HeadUnitQtClass::setGear(quint16 _gear)
{
    sender.IPCManagerTargetProxy->setGearMode(_gear, sender.callStatus, sender.returnMessage);
}

// QML-invokable method to set the direction using IPCManagerTargetProxy
Q_INVOKABLE void HeadUnitQtClass::setDirection(quint16 _direction)
{
    uint16_t temp = 0;
    while (1)
    {
        sender.IPCManagerTargetProxy->setDirection(temp, sender.callStatus, sender.returnMessage);
        temp = (temp + 1) % 4;
        usleep(2000000);
    }
}

// QML-invokable method to set the light using IPCManagerTargetProxy
Q_INVOKABLE void HeadUnitQtClass::setLight(QString _light)
{
    sender.IPCManagerTargetProxy->setLight(_light.toStdString(), sender.callStatus, sender.returnMessage);
}

// QML-invokable method to power off the system
Q_INVOKABLE void HeadUnitQtClass::poweroff()
{
    // Execute the system command to power off the system
    int exitCode = system("poweroff");
}

// Create an instance of HeadUnitQtClass named carinfo
HeadUnitQtClass carinfo;

