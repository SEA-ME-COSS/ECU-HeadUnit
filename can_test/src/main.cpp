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

        // Obtain the CAN bus device
        canDevice = QCanBus::instance()->createDevice("socketcan", "can0", &errorString);
        if (!canDevice) {
            qCritical() << "Failed to create CAN device:" << errorString;
            return;
        }

        // Connect the received signal to the slot
        connect(canDevice, &QCanBusDevice::framesReceived, this, &CanBusHandler::processReceivedFrames);

        // Try to connect to the CAN interface
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
            QCanBusFrame frame = m_canDevice->readFrame();
            if (frame.frameId() == QString("0x0").toUInt(nullptr, 16)) {
                qDebug() << "helloworld" << frame.toString();
            }
        }
    }

private:
    QCanBusDevice *canDevice = nullptr;
    QString errorString;
};

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    CanBusHandler handler;

    return app.exec();
}

#include "main.moc"
