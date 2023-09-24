import QtQuick 2.2

Item {
    id: valueSource

    property int speed: 0
    property int rpm: 0
    property int battery: 0
    property int gear: 0
    property int direction: 0

    property int left_direction: 0
    property int right_direction: 0

    //function run_ui() {
    //    valueSource.speed = carinfo.getSpeed()
    //    valueSource.battery = carinfo.getBattery()
    //    valueSource.rpm = carinfo.getRpm()
    //}

    function blink_left() {
        valueSource.left_direction = (valueSource.left_direction === 0) ? 1 : 0
    }
    function blink_right() {
        valueSource.right_direction = (valueSource.right_direction) === 0 ? 1 : 0
    }
    function blink_direction() {
        if (valueSource.direction === 1) {
            valueSource.blink_left()
        } else if (valueSource.direction === 2) {
            valueSource.blink_right()
        }
    }

    Timer {
       interval: 500; running: true; repeat: true
       onTriggered: valueSource.blink_direction()
    }
}
