#ifndef CARINFORMATION_HPP
#define CARINFORMATION_HPP


#include <QObject>


class CarInformation : public QObject
{
    Q_OBJECT

public:
    explicit CarInformation(QObject *parent = nullptr);

public Q_SLOTS:
    QString setSpeedRPM(quint16 _sensorRPM);
    QString setBattery(quint16 _battery);
    QString setGear(quint16 _gear);
    QString setDirection(quint16 _direction);

    Q_INVOKABLE quint16 getSpeed();
    Q_INVOKABLE quint16 getRPM();
    Q_INVOKABLE quint16 getBattery();
    Q_INVOKABLE quint16 getGear();
    Q_INVOKABLE quint16 getDirection();

private:
    quint16 speed;
    quint16 rpm;
    quint16 battery;
    quint16 gear;
    quint16 direction;
};


#endif

