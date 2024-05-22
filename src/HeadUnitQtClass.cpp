#include "HeadUnitQtClass.hpp"

HeadUnitQtClass::HeadUnitQtClass(QObject *parent) : QObject(parent) {
    Qsteering = 0.0;
    Qthrottle = 0.0;

    canDevice = QCanBus::instance()->createDevice("socketcan", "can0", &errorString);

    if (!canDevice) {
        qDebug() << "Failed to create CAN device:" << errorString;
        return;
    }

    connect(canDevice, &QCanBusDevice::framesReceived, this, &HeadUnitQtClass::processReceivedFrames);

    if (!canDevice->connectDevice()) {
        qDebug() << "Failed to connect to CAN device:" << canDevice->errorString();
        delete canDevice;
        canDevice = nullptr;
    }
}

HeadUnitQtClass::~HeadUnitQtClass() {
    if (canDevice) {
        canDevice->disconnectDevice();
        delete canDevice;
    }
}

qreal HeadUnitQtClass::steering() const {
    return Qsteering;
}

qreal HeadUnitQtClass::throttle() const {
    return Qthrottle;
}

void HeadUnitQtClass::setSteering(qreal _steering) {
    Qsteering = _steering;
    emit steeringChanged();
}

void HeadUnitQtClass::setThrottle(qreal _throttle) {
    Qthrottle = _throttle;
    emit throttleChanged();
}

void HeadUnitQtClass::processReceivedFrames() {
    while (canDevice->framesAvailable()) {
        QCanBusFrame frame = canDevice->readFrame();
        QByteArray payload = frame.payload();
        for (int i = 0; i < PAYLOAD_SIZE; i++) {
            data[i] = static_cast<quint8>(payload[i]);
        }

        if (frame.frameId() == steering_id) {  // steering
            decryption = data[1] + data[2] * 0.01;
            if (data[0] == 1) {
                decryption *= -1;
            }

            setSteering(decryption);
            continue;
        }

        if (frame.frameId() == throttle_id) {  // throttle
            decryption = data[1] + data[2] * 0.01;
            if (data[0] == 1) {
                decryption *= -1;
            }

            setThrottle(decryption);
            continue;
        }
    }
}
