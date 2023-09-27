import QtQuick 2.2
import DataModule 1.0

Item {
    id: valueSource

    QtFunction {
        id: carinfo
    }

    property int speed: 0
    property int rpm: 0
    property int battery: 0
    property int gear: 0
    property int direction: 0

    property int left_direction: 0
    property int right_direction: 0

    Behavior on speed {
        NumberAnimation {
            target: valueSource
            property: "speed"
            easing.type: Easing.InOutSine
            duration: 250
        }
    }
    Behavior on rpm {
        NumberAnimation {
            target: valueSource
            property: "rpm"
            easing.type: Easing.InOutSine
            duration: 250
        }
    }
    Behavior on battery {
        NumberAnimation {
            target: valueSource
            property: "battery"
            easing.type: Easing.InOutSine
            duration: 250
        }
    }

    function blink_left() {
        valueSource.left_direction = (valueSource.left_direction === 0) ? 1 : 0
    }
    function blink_right() {
        valueSource.right_direction = (valueSource.right_direction === 0) ? 1 : 0
    }

    function run_ui() {
        valueSource.speed = carinfo.getSpeed()
        valueSource.rpm = carinfo.getRPM()
        valueSource.battery = carinfo.getBattery()
        valueSource.gear = carinfo.getGear()
        valueSource.direction = carinfo.getDirection()

        if (valueSource.direction === 1) {
            valueSource.blink_left()
        } else if (valueSource.direction === 2) {
            valueSource.blink_right()
        } else {
            valueSource.left_direction = 0
            valueSource.right_direction = 0
        }
    }

    Timer {
        interval: 100; running: true; repeat: true
        onTriggered: valueSource.run_ui()
    }
}
