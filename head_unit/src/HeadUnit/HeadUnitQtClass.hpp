#ifndef HEADUNITQTCLASS_HPP
#define HEADUNITQTCLASS_HPP


#include <string>
#include <QObject>
#include <QString>

#include "HeadUnitSenderClass.hpp"


class HeadUnitQtClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint16 sensorRpm READ sensorRpm WRITE setSensorRpm NOTIFY sensorRpmChanged)
    		
private:
    HeadUnitSenderClass sender;
    
    quint16 QsensorRpm;

public:
    explicit HeadUnitQtClass(QObject *parent = nullptr);
    
    quint16 sensorRpm() const;
    void setSensorRpm(uint16_t _sensorRpm);
    
public Q_SLOTS:
    Q_INVOKABLE void setGear(quint16 _gear);
    Q_INVOKABLE void setDirection(quint16 _direction);
    Q_INVOKABLE void setLight(QString _light);

signals:
    void sensorRpmChanged();
};


extern HeadUnitQtClass carinfo;


#endif

