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
        source: "../font/Nebula-Regular.otf"
    }

    ValueSource {
        id: valueSource
    }

    HeadUnitQtClass {
        id: manager
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
            color: (carinfo.sensorRpm === 0) ? "black" : "#555555"
            radius: 30

            Rectangle {
                width: 115
                height: 115
                anchors.centerIn: parent
                color: (valueSource.gear === 0) ? ((carinfo.sensorRpm === 0) ? "#555555" : "#B0B0B0") : "white"
                radius: 22

                Text {
                    text: "P"
                    font.family: font.name
                    font.pixelSize: 130
                    color: (valueSource.gear === 0) ? "white" : ((carinfo.sensorRpm === 0) ? "#555555" : "#B0B0B0")
                    x: 13
                    y: -20
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (carinfo.sensorRpm === 0) {
                        valueSource.gear = 0
                        manager.setGear(0)
                    }
                }
            }
        }

        Rectangle {
            width: 130
            height: 130
            x: 20
            y: parent.height / 2 - height / 2 - 70
            color: (carinfo.sensorRpm === 0) ? "black" : "#555555"
            radius: 30

            Rectangle {
                width: 115
                height: 115
                anchors.centerIn: parent
                color: (valueSource.gear === 1) ? ((carinfo.sensorRpm === 0) ? "#555555" : "#B0B0B0") : "white"
                radius: 22

                Text {
                    text: "R"
                    font.family: font.name
                    font.pixelSize: 130
                    color: (valueSource.gear === 1) ? "white" : ((carinfo.sensorRpm === 0) ? "#555555" : "#B0B0B0")
                    x: 13
                    y: -20
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (carinfo.sensorRpm === 0) {
                        valueSource.gear = 1
                        manager.setGear(1)
                    }
                }
            }
        }

        Rectangle {
            width: 130
            height: 130
            x: 20
            y: parent.height / 2 - height / 2 + 70
            color: (carinfo.sensorRpm === 0) ? "black" : "#555555"
            radius: 30

            Rectangle {
                width: 115
                height: 115
                anchors.centerIn: parent
                color: (valueSource.gear === 2) ? ((carinfo.sensorRpm === 0) ? "#555555" : "#B0B0B0") : "white"
                radius: 22

                Text {
                    text: "N"
                    font.family: font.name
                    font.pixelSize: 130
                    color: (valueSource.gear === 2) ? "white" : ((carinfo.sensorRpm === 0) ? "#555555" : "#B0B0B0")
                    x: 13
                    y: -20
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (carinfo.sensorRpm === 0) {
                        valueSource.gear = 2
                        manager.setGear(2)
                    }
                }
            }
        }

        Rectangle {
            width: 130
            height: 130
            x: 20
            y: parent.height / 2 - height / 2 + 210
            color: (carinfo.sensorRpm === 0) ? "black" : "#555555"
            radius: 30

            Rectangle {
                width: 115
                height: 115
                anchors.centerIn: parent
                color: (valueSource.gear === 3) ? ((carinfo.sensorRpm === 0) ? "#555555" : "#B0B0B0") : "white"
                radius: 22

                Text {
                    text: "D"
                    font.family: font.name
                    font.pixelSize: 130
                    color: (valueSource.gear === 3) ? "white" : ((carinfo.sensorRpm === 0) ? "#555555" : "#B0B0B0")
                    x: 13
                    y: -20
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (carinfo.sensorRpm === 0) {
                        valueSource.gear = 3
                        manager.setGear(3)
                    }
                }
            }
        }

        Rectangle {
            width: 5
            height: parent.height
            anchors.verticalCenter: parent.verticalCenter
            x: parent.width / 2 - width / 2 - 340
            color: (carinfo.sensorRpm === 0) ? "black" : "#555555"
        }

        Text {
            text: carinfo.sensorRpm
            font.family: font.name
            font.pixelSize: 70
            color: (carinfo.sensorRpm === 0) ? "black" : "#555555"
            x: 200
            y: 5
        }

        Image {
            source: "../image/turn-icon.png"
            width: 100
            height: 100
            rotation: -90
            fillMode: Image.PreserveAspectFit
            opacity: (valueSource.left_on_off) ? 0.2 : 1.0
            x: parent.width / 2 - width / 2 - 170
            y: 470

            Image {
                source: "../image/turn-icon.png"
                width: 80
                height: 80
                fillMode: Image.PreserveAspectFit
                anchors.horizontalCenter: parent.horizontalCenter
                y: 12
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (valueSource.direction === 1) {
                        manager.setDirection(0)
                        valueSource.direction = 0

                        valueSource.blink = false
                        valueSource.left_direction = false
                        valueSource.right_direction = false
                        valueSource.left_on_off = false
                        valueSource.right_on_off = false
                    } else {
                        manager.setDirection(1)
                        valueSource.direction = 1

                        valueSource.blink = true
                        valueSource.left_direction = true
                        valueSource.right_direction = false
                        valueSource.left_on_off = true
                        valueSource.right_on_off = false
                    }
                }
            }
        }

        Image {
            source: "../image/turn-icon.png"
            width: 100
            height: 100
            rotation: 90
            fillMode: Image.PreserveAspectFit
            opacity: (valueSource.right_on_off) ? 0.2 : 1.0
            x: parent.width / 2 - width / 2 + 170
            y: 470

            Image {
                source: "../image/turn-icon.png"
                width: 80
                height: 80
                fillMode: Image.PreserveAspectFit
                anchors.horizontalCenter: parent.horizontalCenter
                y: 12
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (valueSource.direction === 2) {
                        manager.setDirection(0)
                        valueSource.direction = 0

                        valueSource.blink = false
                        valueSource.left_direction = false
                        valueSource.right_direction = false
                        valueSource.left_on_off = false
                        valueSource.right_on_off = false
                    } else {
                        manager.setDirection(2)
                        valueSource.direction = 2

                        valueSource.blink = true
                        valueSource.left_direction = false
                        valueSource.right_direction = true
                        valueSource.left_on_off = false
                        valueSource.right_on_off = true
                    }
                }
            }
        }

        Image {
            source: "../image/warning-icon.png"
            width: 120
            height: 120
            fillMode: Image.PreserveAspectFit
            anchors.horizontalCenter: parent.horizontalCenter
            y: 460

            Image {
                source: "../image/warning-icon.png"
                width: 90
                height: 90
                fillMode: Image.PreserveAspectFit
                anchors.horizontalCenter: parent.horizontalCenter
                y: 20

                Image {
                    source: "../image/warning-icon.png"
                    width: 65
                    height: 65
                    fillMode: Image.PreserveAspectFit
                    anchors.horizontalCenter: parent.horizontalCenter
                    y: 17
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (valueSource.direction === 3) {
                        manager.setDirection(0)
                        valueSource.direction = 0

                        valueSource.blink = false
                        valueSource.left_direction = false
                        valueSource.right_direction = false
                        valueSource.left_on_off = false
                        valueSource.right_on_off = false
                    } else {
                        manager.setDirection(3)
                        valueSource.direction = 3

                        valueSource.blink = true
                        valueSource.left_direction = true
                        valueSource.right_direction = true
                        valueSource.left_on_off = true
                        valueSource.right_on_off = true
                    }
                }
            }
        }

        Rectangle {
            width: 5
            height: parent.height
            anchors.verticalCenter: parent.verticalCenter
            x: parent.width / 2 - width / 2 + 340
            color: (carinfo.sensorRpm === 0) ? "black" : "#555555"
        }
    }
}
