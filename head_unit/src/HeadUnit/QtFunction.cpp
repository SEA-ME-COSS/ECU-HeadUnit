#include "QtFunction.hpp"


QtFunction::QtFunction(QObject *parent) : QObject(parent) { }

Q_INVOKABLE void QtFunction::setGear(quint16 _gear)
{
    pthread_mutex_lock(&HeadUnitDataMutex);
    gear = _gear;
    pthread_mutex_unlock(&HeadUnitDataMutex);
    
    return;
}

Q_INVOKABLE void QtFunction::setDirection(quint16 _direction)
{
    pthread_mutex_lock(&HeadUnitDataMutex);
    direction = _direction;
    pthread_mutex_unlock(&HeadUnitDataMutex);
    
    return;
}

Q_INVOKABLE quint16 QtFunction::getSensorRpm()
{
    pthread_mutex_lock(&HeadUnitDataMutex);
    temp = sensorRpm;
    pthread_mutex_unlock(&HeadUnitDataMutex);
    
    return temp;
}

