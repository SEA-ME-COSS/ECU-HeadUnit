#include <QObject>
#include <QCanBus>
#include <QCanBusDevice>
#include <QCanBusFrame>

class CANBusReceiver : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString canValue READ canValue NOTIFY canValueChanged)

public:
    explicit CANBusReceiver(QObject *parent = nullptr)
        : QObject(parent), m_canBusDevice(nullptr), m_canValue("")
    {
        initializeCanBus();
    }

    QString canValue() const
    {
        return m_canValue;
    }

signals:
    void canValueChanged();

private slots:
    void processReceivedFrames()
    {
        while (m_canBusDevice->framesAvailable()) {
            const QCanBusFrame frame = m_canBusDevice->readFrame();
            // 예제에서는 프레임의 데이터를 QString으로 변환하여 저장합니다.
            m_canValue = QString::fromLatin1(frame.payload());
            emit canValueChanged();
        }
    }

private:
    void initializeCanBus()
    {
        m_canBusDevice = QCanBus::instance()->createDevice("socketcan", "can0", this);
        if (!m_canBusDevice) {
            qWarning() << "Failed to create CAN bus device";
            return;
        }

        connect(m_canBusDevice, &QCanBusDevice::framesReceived, this, &CANBusReceiver::processReceivedFrames);

        if (!m_canBusDevice->connectDevice()) {
            qWarning() << "Failed to connect to CAN bus device";
            delete m_canBusDevice;
            m_canBusDevice = nullptr;
        }
    }

    QCanBusDevice *m_canBusDevice;
    QString m_canValue;
};
