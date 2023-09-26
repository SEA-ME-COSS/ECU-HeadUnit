import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

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

    Item {
        id: container
        width: 1024
        height: 600
        anchors.centerIn: parent
        rotation: 0

        Rectangle {
            id: background
            width: 1024
            height: 600
            anchors.centerIn: parent
            rotation: 90
            gradient: Gradient {
                GradientStop { position: 0.0; color: "gray" }
                GradientStop { position: 0.4; color: "white" }
                GradientStop { position: 0.6; color: "white" }
                GradientStop { position: 1.0; color: "gray" }
            }
        }

        Image {
            source: "image/logo.png"
            width: 300
            height: 300
            fillMode: Image.PreserveAspectFit
            anchors.horizontalCenter: parent.horizontalCenter
            y: 20
        }

        Text {
            text: valueSource.sensorRpm
            font.family: font.name
            font.pixelSize: 70
            color: "black"
            anchors.horizontalCenter: parent.horizontalCenter
            y: 400
        }
    }
}
