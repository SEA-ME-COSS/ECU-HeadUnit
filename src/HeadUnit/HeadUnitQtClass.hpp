#ifndef HEADUNITQTCLASS_HPP
#define HEADUNITQTCLASS_HPP

#include <string>
#include <QObject>
#include <QString>
#include <cstdlib>

#include "HeadUnitSenderClass.hpp"

class HeadUnitQtClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint16 sensorRpm READ sensorRpm WRITE setSensorRpm NOTIFY sensorRpmChanged)
    Q_PROPERTY(quint16 steering READ steering WRITE setSteering NOTIFY steeringChanged)

private:
    HeadUnitSenderClass sender;  // Create an instance of HeadUnitSenderClass for communication

    quint16 QsensorRpm;  // Store sensor RPM data
    quint16 Qsteering;   // Store steering data

public:
    explicit HeadUnitQtClass(QObject *parent = nullptr);

    quint16 sensorRpm() const;  // Getter for sensor RPM
    quint16 steering() const;  // Getter for steering data

    void setSensorRpm(uint16_t _sensorRpm);  // Setter for sensor RPM
    void setSteering(uint16_t _steering);      // Setter for steering data

public Q_SLOTS:
    Q_INVOKABLE void setGear(quint16 _gear);          // QML-invokable method to set gear
    Q_INVOKABLE void setDirection(quint16 _direction);  // QML-invokable method to set direction
    Q_INVOKABLE void setLight(QString _light);         // QML-invokable method to set light
    Q_INVOKABLE void poweroff();                       // QML-invokable method to power off the system

signals:
    void sensorRpmChanged();   // Signal for sensor RPM changes
    void steeringChanged();    // Signal for steering data changes
};

extern HeadUnitQtClass carinfo;  // Create a global instance of HeadUnitQtClass named 'carinfo'

#endif

