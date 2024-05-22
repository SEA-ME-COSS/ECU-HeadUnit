#ifndef HEADUNITQTCLASS_HPP
#define HEADUNITQTCLASS_HPP

#include <QObject>
#include <QCanBus>
#include <QCanBusDevice>
#include <QCanBusFrame>
#include <QDebug>

class HeadUnitQtClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal steering READ steering WRITE setSteering NOTIFY steeringChanged)
    Q_PROPERTY(qreal throttle READ throttle WRITE setThrottle NOTIFY throttleChanged)

private:
    qreal Qsteering;
    qreal Qthrottle;

    quint32 steering_id = QString("0x00").toUInt(nullptr, 16);
    quint32 throttle_id = QString("0x01").toUInt(nullptr, 16);

    QCanBusDevice *canDevice = nullptr;
    QString errorString;
    static const int PAYLOAD_SIZE = 4;
    quint8 data[PAYLOAD_SIZE];
    qreal decryption;

private slots:
    void processReceivedFrames();

public:
    explicit HeadUnitQtClass(QObject *parent = nullptr);
    ~HeadUnitQtClass();

    qreal steering() const;
    qreal throttle() const;

    void setSteering(qreal _steering);
    void setThrottle(qreal _throttle);

signals:
    void steeringChanged();
    void throttleChanged();
};

#endif
