import QtQuick 2.2

Item {
    id: valueSource

    property int gear: 0
    property int direction: 0

    property bool blink: false
    property bool left_direction: false
    property bool right_direction: false
    property bool left_on_off: false
    property bool right_on_off: false

    function blinking() {
        if (valueSource.left_direction) {
            valueSource.left_on_off = (valueSource.left_on_off) ? false : true
        }
        if (valueSource.right_direction) {
            valueSource.right_on_off = (valueSource.right_on_off) ? false : true
        }
    }

    Timer {
        interval: 500; running: valueSource.blink; repeat: true
        onTriggered: valueSource.blinking()
    }
}
