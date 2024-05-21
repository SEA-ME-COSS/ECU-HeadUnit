#ifndef HEADUNITQTCLASS_HPP
#define HEADUNITQTCLASS_HPP

#include <QObject>
#include <QCanBus>
#include <QCanBusDevice>
#include <QCanBusFrame>

class HeadUnitQtClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint8 throttle READ throttle WRITE setThrottle NOTIFY throttleChanged)

private:
    quint8 Qthrottle;

    QCanBusDevice *canDevice = nullptr;
    QString errorString;

    quint32 steering_id = QString("0x00").toUInt(nullptr, 16);

    static const int PAYLOAD_SIZE = 4;
    quint8 data[PAYLOAD_SIZE];

private slots:
    void processReceivedFrames();

public:
    explicit HeadUnitQtClass(QObject *parent = nullptr);
    explicit ~HeadUnitQtClass();

    quint8 throttle() const;

    void setThrottle(quint8 _throttle);

signals:
    void throttleChanged();
};

extern HeadUnitQtClass carinfo;

#endif
