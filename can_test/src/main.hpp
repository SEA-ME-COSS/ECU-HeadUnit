#include <QCoreApplication>
#include <QCanBus>
#include <QCanBusDevice>
#include <QCanBusFrame>
#include <QDebug>

class CanBusHandler : public QObject {
    Q_OBJECT

public:
    CanBusHandler(QObject *parent = nullptr)
        : QObject(parent) {

        canDevice = QCanBus::instance()->createDevice("socketcan", "can0", &errorString);
        if (!canDevice) {
            qCritical() << "Failed to create CAN device:" << errorString;
            return;
        }

        connect(canDevice, &QCanBusDevice::framesReceived, this, &CanBusHandler::processReceivedFrames);

        if (!canDevice->connectDevice()) {
            qCritical() << "Failed to connect to CAN device:" << canDevice->errorString();
            delete canDevice;
            canDevice = nullptr;
        }
    }

    ~CanBusHandler() {
        if (canDevice) {
            canDevice->disconnectDevice();
            delete canDevice;
        }
    }

private slots:
    void processReceivedFrames() {
        while (canDevice->framesAvailable()) {
            QCanBusFrame frame = canDevice->readFrame();
            if (frame.frameId() == steering_id) {
                QByteArray payload = frame.payload();

                for (int i = 0; i < PAYLOAD_SIZE; i++) {
                    data[i] = static_cast<quint8>(payload[i]);
                }

                qDebug() << data[0] << data[1] << data[2] << data[3];
            }
        }
    }

private:
    QCanBusDevice *canDevice = nullptr;
    QString errorString;

    quint32 steering_id = QString("0x00").toUInt(nullptr, 16);

    static const int PAYLOAD_SIZE = 4;
    quint8 data[PAYLOAD_SIZE];
};

// #include "main.moc"
