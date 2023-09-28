import QtQuick 2.2
import DataModule 1.0

Item {
    id: valueSource

    QtFunction {
        id: carinfo
    }

    property int sensorRpm: 0
    property int gear: 0

    function run_ui() {
        valueSource.sensorRpm = carinfo.getSensorRpm()
    }

    Timer {
        interval: 100; running: true; repeat: true
        onTriggered: valueSource.run_ui()
    }
}
