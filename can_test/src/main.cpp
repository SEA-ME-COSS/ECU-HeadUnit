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

                for (int i = 0; i < payload.size(); ++i) {
                    qDebug() << payload[i];
                }

            }
        }
    }

private:
    QCanBusDevice *canDevice = nullptr;
    QString errorString;

    quint32 steering_id = QString("0x00").toUInt(nullptr, 16);
};

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    CanBusHandler handler;

    return app.exec();
}

#include "main.moc"
