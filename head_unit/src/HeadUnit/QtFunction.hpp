#ifndef QTFUNCTION_HPP
#define QTFUNCTION_HPP


#include <QObject>

#include "HeadUnitData.hpp"


class QtFunction : public QObject
{
    Q_OBJECT

public:
    explicit QtFunction(QObject *parent = nullptr);

public Q_SLOTS:
    Q_INVOKABLE void setGear(quint16 _gear);
    Q_INVOKABLE void setDirection(quint16 _direction);
    
    Q_INVOKABLE quint16 getSensorRpm();    
};


#endif

