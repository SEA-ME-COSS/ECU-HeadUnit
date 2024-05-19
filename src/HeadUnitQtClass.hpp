#ifndef HEADUNITQTCLASS_HPP
#define HEADUNITQTCLASS_HPP

#include <string>
#include <QObject>
#include <cstdlib>

class HeadUnitQtClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint16 sensorRpm READ sensorRpm WRITE setSensorRpm NOTIFY sensorRpmChanged)
    Q_PROPERTY(quint16 direction READ direction WRITE setDirection NOTIFY directionChanged)

private:
    quint16 QsensorRpm;
    quint16 Qdirection;

public:
    explicit HeadUnitQtClass(QObject *parent = nullptr);

    quint16 sensorRpm() const;
    quint16 direction() const;

    void setSensorRpm(uint16_t _sensorRpm);
    void setDirection(uint16_t _direction);

public Q_SLOTS:
    Q_INVOKABLE void poweroff();

signals:
    void sensorRpmChanged();
    void directionChanged();
};

extern HeadUnitQtClass carinfo;

#endif
