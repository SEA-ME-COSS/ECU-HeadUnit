import QtQuick 2.2
import DataModule 1.0

Item {
    id: valueSource

    QtFunction {
        id: carinfo
    }

    property int sensorRpm: 0
    property int gear: 0
    property int direction: 0

    property bool blink: false
    property bool left_direction: false
    property bool right_direction: false
    property bool left_on_off: false
    property bool right_on_off: false

    function run_ui() {
        valueSource.sensorRpm = carinfo.getSensorRpm()
    }

    function blinking() {
        if (valueSource.left_direction) {
            valueSource.left_on_off = (valueSource.left_on_off) ? false : true
        }
        if (valueSource.right_direction) {
            valueSource.right_on_off = (valueSource.right_on_off) ? false : true
        }
    }

    Timer {
        interval: 100; running: true; repeat: true
        onTriggered: valueSource.run_ui()
    }

    Timer {
        interval: 500; running: valueSource.blink; repeat: true
        onTriggered: valueSource.blinking()
    }
}
