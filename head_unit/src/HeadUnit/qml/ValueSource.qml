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
            valueSource.left_on_off = !valueSource.left_on_off
        }
        if (valueSource.right_direction) {
            valueSource.right_on_off = !valueSource.right_on_off
        }
    }

    Timer {
        interval: 500; running: valueSource.blink; repeat: true
        onTriggered: valueSource.blinking()
    }

    property string red: "80"
    property string green: "80"
    property string blue: "80"
    property string light: "#" + valueSource.red + valueSource.green + valueSource.blue

    property int mode: 0

    property var currentTime: 0
    property int hours: 0
    property int minutes: 0
    property string formattedHours: ""
    property string formattedMinutes: ""
    property string clock: "00:00"

    Timer {
        interval: 1000; running: true; repeat: true
        onTriggered: {
            valueSource.currentTime = new Date();
            valueSource.hours = valueSource.currentTime.getHours();
            valueSource.minutes = valueSource.currentTime.getMinutes();
            valueSource.formattedHours = (valueSource.hours < 10 ? ((valueSource.hours < 1) ? "00" : "0") : "") + valueSource.hours;
            valueSource.formattedMinutes = (valueSource.minutes < 10 ? ((valueSource.minutes < 1) ? "00" : "0") : "") + valueSource.minutes;
            valueSource.clock = valueSource.formattedHours + ":" + valueSource.formattedMinutes;
        }
    }               
}
