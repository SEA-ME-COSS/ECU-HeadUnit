#include "QtFunction.hpp"


QtFunction::QtFunction(QObject *parent) : QObject(parent) { }

Q_INVOKABLE quint16 QtFunction::getSpeed()
{
    pthread_mutex_lock(&CarInformationMutex);
    temp = speed;
    pthread_mutex_unlock(&CarInformationMutex);
    return temp;
}

Q_INVOKABLE quint16 QtFunction::getRPM()
{
    pthread_mutex_lock(&CarInformationMutex);
    temp = rpm;
    pthread_mutex_unlock(&CarInformationMutex);
    return temp;
}

Q_INVOKABLE quint16 QtFunction::getBattery()
{
    pthread_mutex_lock(&CarInformationMutex);
    temp = battery;
    pthread_mutex_unlock(&CarInformationMutex);
    return temp;
}

Q_INVOKABLE quint16 QtFunction::getGear()
{
    pthread_mutex_lock(&CarInformationMutex);
    temp = gear;
    pthread_mutex_unlock(&CarInformationMutex);
    return temp;
}

Q_INVOKABLE quint16 QtFunction::getDirection()
{
    pthread_mutex_lock(&CarInformationMutex);
    temp = direction;
    pthread_mutex_unlock(&CarInformationMutex);
    return temp;
}

