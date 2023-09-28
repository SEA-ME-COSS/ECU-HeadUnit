import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4
import DataModule 1.0

Window {
    id: root
    title: "Head Unit"
    width: 1024
    height: 600
    //width: 600
    //height: 1024
    visible: true

    FontLoader {
        id: font
        source: "font/Nebula-Regular.otf"
    }

    ValueSource {
        id: valueSource
    }

    QtFunction {
        id: carinfo
    }

    Item {
        id: container
        width: 1024
        height: 600
        anchors.centerIn: parent
        rotation: 0

        Rectangle {
            id: background
            width: 600
            height: 1024
            anchors.centerIn: parent
            rotation: 90
            gradient: Gradient {
                GradientStop { position: 0.0; color: "gray" }
                GradientStop { position: 0.4; color: "white" }
                GradientStop { position: 0.6; color: "white" }
                GradientStop { position: 1.0; color: "gray" }
            }
        }

        Rectangle {
            width: 130
            height: 130
            x: 20
            y: parent.height / 2 - height / 2 - 210
            color: (valueSource.sensorRpm === 0) ? "black" : "#555555"
            radius: 30

            Rectangle {
                width: 115
                height: 115
                anchors.centerIn: parent
                color: (valueSource.gear === 0) ? ((valueSource.sensorRpm === 0) ? "#555555" : "#B0B0B0") : "white"
                radius: 22

                Text {
                    text: "P"
                    font.family: font.name
                    font.pixelSize: 130
                    color: (valueSource.gear === 0) ? "white" : ((valueSource.sensorRpm === 0) ? "#555555" : "#B0B0B0")
                    x: 13
                    y: -20
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (valueSource.sensorRpm === 0) {
                        valueSource.gear = 0
                        carinfo.setGear(0)
                    }
                }
            }
        }

        Rectangle {
            width: 130
            height: 130
            x: 20
            y: parent.height / 2 - height / 2 - 70
            color: (valueSource.sensorRpm === 0) ? "black" : "#555555"
            radius: 30

            Rectangle {
                width: 115
                height: 115
                anchors.centerIn: parent
                color: (valueSource.gear === 1) ? ((valueSource.sensorRpm === 0) ? "#555555" : "#B0B0B0") : "white"
                radius: 22

                Text {
                    text: "R"
                    font.family: font.name
                    font.pixelSize: 130
                    color: (valueSource.gear === 1) ? "white" : ((valueSource.sensorRpm === 0) ? "#555555" : "#B0B0B0")
                    x: 13
                    y: -20
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (valueSource.sensorRpm === 0) {
                        valueSource.gear = 1
                        carinfo.setGear(1)
                    }
                }
            }
        }

        Rectangle {
            width: 130
            height: 130
            x: 20
            y: parent.height / 2 - height / 2 + 70
            color: (valueSource.sensorRpm === 0) ? "black" : "#555555"
            radius: 30

            Rectangle {
                width: 115
                height: 115
                anchors.centerIn: parent
                color: (valueSource.gear === 2) ? ((valueSource.sensorRpm === 0) ? "#555555" : "#B0B0B0") : "white"
                radius: 22

                Text {
                    text: "N"
                    font.family: font.name
                    font.pixelSize: 130
                    color: (valueSource.gear === 2) ? "white" : ((valueSource.sensorRpm === 0) ? "#555555" : "#B0B0B0")
                    x: 13
                    y: -20
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (valueSource.sensorRpm === 0) {
                        valueSource.gear = 2
                        carinfo.setGear(2)
                    }
                }
            }
        }

        Rectangle {
            width: 130
            height: 130
            x: 20
            y: parent.height / 2 - height / 2 + 210
            color: (valueSource.sensorRpm === 0) ? "black" : "#555555"
            radius: 30

            Rectangle {
                width: 115
                height: 115
                anchors.centerIn: parent
                color: (valueSource.gear === 3) ? ((valueSource.sensorRpm === 0) ? "#555555" : "#B0B0B0") : "white"
                radius: 22

                Text {
                    text: "D"
                    font.family: font.name
                    font.pixelSize: 130
                    color: (valueSource.gear === 3) ? "white" : ((valueSource.sensorRpm === 0) ? "#555555" : "#B0B0B0")
                    x: 13
                    y: -20
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (valueSource.sensorRpm === 0) {
                        valueSource.gear = 3
                        carinfo.setGear(3)
                    }
                }
            }
        }

        Rectangle {
            width: 5
            height: parent.height
            anchors.verticalCenter: parent.verticalCenter
            x: 170
            color: (valueSource.sensorRpm === 0) ? "black" : "#555555"
        }

        Text {
            text: valueSource.sensorRpm
            font.family: font.name
            font.pixelSize: 70
            color: (valueSource.sensorRpm === 0) ? "black" : "#555555"
            x: 200
            y: 5
        }
    }
}
