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
        m_canDevice = QCanBus::instance()->createDevice("socketcan", "can0", &m_errorString);
        if (!m_canDevice) {
            qCritical() << "Failed to create CAN device:" << m_errorString;
            return;
        }

        // Connect the received signal to the slot
        connect(m_canDevice, &QCanBusDevice::framesReceived, this, &CanBusHandler::processReceivedFrames);

        // Try to connect to the CAN interface
        if (!m_canDevice->connectDevice()) {
            qCritical() << "Failed to connect to CAN device:" << m_canDevice->errorString();
            delete m_canDevice;
            m_canDevice = nullptr;
        }
    }

    ~CanBusHandler() {
        if (m_canDevice) {
            m_canDevice->disconnectDevice();
            delete m_canDevice;
        }
    }

private slots:
    void processReceivedFrames() {
        while (m_canDevice->framesAvailable()) {
            QCanBusFrame frame = m_canDevice->readFrame();
            if (frame.frameId() == QString("0x0").toUInt(nullptr, 16)) {
                qDebug() << "helloworld" << frame.toString();
            }
        }
    }

private:
    QCanBusDevice *m_canDevice = nullptr;
    QString m_errorString;
};



int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    CanBusHandler handler;

    return app.exec();
}

#include "main.moc"
