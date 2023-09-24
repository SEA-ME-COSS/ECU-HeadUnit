import QtQuick 2.2
import DataModule 1.0

Item {
    id: valueSource

    CarInformation {
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
            duration: 500
        }
    }
    Behavior on rpm {
        NumberAnimation {
            target: valueSource
            property: "rpm"
            easing.type: Easing.InOutSine
            duration: 500
        }
    }
    Behavior on battery {
        NumberAnimation {
            target: valueSource
            property: "battery"
            easing.type: Easing.InOutSine
            duration: 500
        }
    }

    function blink_left() {
        valueSource.left_direction = (valueSource.left_direction === 0) ? 1 : 0
    }
    function blink_right() {
        valueSource.right_direction = (valueSource.right_direction === 0) ? 1 : 0
    }

    function run_ui() {
        valueSource.speed = carinfo.getQSpeed()
        valueSource.rpm = carinfo.getQRPM()
        valueSource.battery = carinfo.getQBattery()
        valueSource.gear = carinfo.getQGear()
        valueSource.direction = carinfo.getQDirection()

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
        interval: 500; running: true; repeat: true
        onTriggered: valueSource.run_ui()
    }
}
