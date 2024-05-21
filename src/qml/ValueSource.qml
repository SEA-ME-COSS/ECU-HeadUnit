import QtQuick 2.2

Item {
    id: valueSource

    property int throttle: carinfo.throttle



    property int direction: carinfo.direction

    // Properties for controlling blinking and direction indicators
    property bool blink: !(valueSource.direction === 0)
    property bool left_direction: (valueSource.direction === 1 || valueSource.direction === 3)
    property bool right_direction: (valueSource.direction === 2 || valueSource.direction === 3)
    property bool left_on_off: false
    property bool right_on_off: false
    property bool initial_delay: !(valueSource.direction === 0)

    onDirectionChanged: {
        valueSource.blink = !(valueSource.direction === 0);
        valueSource.left_direction = (valueSource.direction === 1 || valueSource.direction === 3);
        valueSource.right_direction = (valueSource.direction === 2 || valueSource.direction === 3);
        valueSource.left_on_off = false;
        valueSource.right_on_off = false;
        valueSource.initial_delay = !(valueSource.direction === 0)
    }

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
        onTriggered: {
            if (valueSource.initial_delay) {
                valueSource.initial_delay = false
            } else {
                valueSource.blinking()
            }
        }
    }

    //==================================================//
    //                      Clock                       //
    //==================================================//

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
            valueSource.formattedHours = (valueSource.hours < 10 ? "0" : "") + valueSource.hours;
            valueSource.formattedMinutes = (valueSource.minutes < 10 ? "0" : "") + valueSource.minutes;
            valueSource.clock = valueSource.formattedHours + ":" + valueSource.formattedMinutes;
        }
    }

    //==================================================//
    //                  Ambient Light                   //
    //==================================================//

    property string light: "#808080"

    property int red: 128
    property int green: 128
    property int blue: 128

    property string red_string: "80"
    property string green_string: "80"
    property string blue_string: "80"



    property int mode: 0
}
