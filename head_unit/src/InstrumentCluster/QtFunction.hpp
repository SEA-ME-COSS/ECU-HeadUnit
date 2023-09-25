#ifndef QTFUNCTION_HPP
#define QTFUNCTION_HPP


#include <QObject>

#include "InstrumentClusterData.hpp"


class QtFunction : public QObject
{
    Q_OBJECT

public:
    explicit QtFunction(QObject *parent = nullptr);

public Q_SLOTS:
    Q_INVOKABLE quint16 getSpeed();
    Q_INVOKABLE quint16 getRPM();
    Q_INVOKABLE quint16 getBattery();
    Q_INVOKABLE quint16 getGear();
    Q_INVOKABLE quint16 getDirection();
    
private:
    uint16_t temp;
};


#endif

