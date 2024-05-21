#include "HeadUnitQtClass.hpp"

HeadUnitQtClass::HeadUnitQtClass(QObject *parent) : QObject(parent)
{
    Qthrottle = 0;

    canDevice = QCanBus::instance()->createDevice("socketcan", "can0", &errorString);
    if (!canDevice)
    {
        qCritical() << "Failed to create CAN device:" << errorString;
        return;
    }

    connect(canDevice, &QCanBusDevice::framesReceived, this, &CanBusHandler::processReceivedFrames);

    if (!canDevice->connectDevice())
    {
        qCritical() << "Failed to connect to CAN device:" << canDevice->errorString();
        delete canDevice;
        canDevice = nullptr;
    }
}

HeadUnitQtClass::~HeadUnitQtClass()
{
    if (canDevice)
    {
        canDevice->disconnectDevice();
        delete canDevice;
    }
}

quint8 HeadUnitQtClass::throttle() const
{
    return Qthrottle;
}

void HeadUnitQtClass::setThrottle(quint8 _throttle)
{
    Qthrottle = _throttle;
    emit throttleChanged();
}

void HeadUnitQtClass::processReceivedFrames() {
    while (canDevice->framesAvailable()) {
        QCanBusFrame frame = canDevice->readFrame();
        if (frame.frameId() == steering_id) {
            QByteArray payload = frame.payload();

            for (int i = 0; i < PAYLOAD_SIZE; i++) {
                data[i] = static_cast<quint8>(payload[i]);
            }

            qDebug() << data[0] << data[1] << data[2] << data[3];

            setThrottle(data[0]);
        }
    }
}

HeadUnitQtClass carinfo;
