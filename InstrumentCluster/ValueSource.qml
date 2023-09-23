import QtQuick 2.2

Item {
    id: valueSource

    property int speed: 0
    property int rpm: 0
    property int battery: 0

    SequentialAnimation {
        running: true
        loops: 1

        PropertyAction {
            target: valueSource
            property: "start"
            value: false
        }

        SequentialAnimation {
            loops: Animation.Infinite

            ParallelAnimation {
                NumberAnimation {
                    target: valueSource
                    property: "speed"
                    easing.type: Easing.InOutSine
                    from: 0
                    to: 200
                    duration: 3000
                }
                NumberAnimation {
                    target: valueSource
                    property: "rpm"
                    easing.type: Easing.InOutSine
                    from: 0
                    to: 400
                    duration: 3000
                }
                NumberAnimation {
                    target: valueSource
                    property: "battery"
                    easing.type: Easing.InOutSine
                    from: 0
                    to: 100
                    duration: 3000
                }
            }
            ParallelAnimation {
                NumberAnimation {
                    target: valueSource
                    property: "speed"
                    easing.type: Easing.InOutSine
                    from: 200
                    to: 0
                    duration: 3000
                }
                NumberAnimation {
                    target: valueSource
                    property: "rpm"
                    easing.type: Easing.InOutSine
                    from: 400
                    to: 0
                    duration: 3000
                }
                NumberAnimation {
                    target: valueSource
                    property: "battery"
                    easing.type: Easing.InOutSine
                    from: 100
                    to: 0
                    duration: 3000
                }
            }
        }
    }
}
