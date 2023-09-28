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

    property bool blink: false
    property bool left_direction: false
    property bool right_direction: false
    property bool left_on_off: false
    property bool right_on_off: false

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

    function run_ui() {
        valueSource.speed = carinfo.getSpeed()
        valueSource.rpm = carinfo.getRPM()
        valueSource.battery = carinfo.getBattery()
        valueSource.gear = carinfo.getGear()
        valueSource.direction = carinfo.getDirection()

        if (valueSource.direction === 1) {
            valueSource.left_direction = true
            valueSource.right_direction = false
            valueSource.blink = true
        } else if (valueSource.direction === 2) {
            valueSource.left_direction = false
            valueSource.right_direction = true
            valueSource.blink = true
        } else if (valueSource.direction === 3) {
            valueSource.left_direction = true
            valueSource.right_direction = true
            valueSource.blink = true
        } else {
            valueSource.left_direction = false
            valueSource.right_direction = false
            valueSource.blink = false
        }
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
