import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

// Create a window named 'root'
Window {
    id: root
    title: "Instrument Cluster"
    width: 400
    height: 1280
    visible: true

    FontLoader {
        id: font
        source: "../font/Nebula-Regular.otf"
    }

    // Create a value source object
    ValueSource {
        id: valueSource
    }

    // Create an item named 'container' to hold the instrument cluster elements
    Item {
        id: container
        width: 1280
        height: 400
        anchors.centerIn: parent
        rotation: -90

        // Create a background rectangle with a gradient
        Rectangle {
            id: background
            width: 400
            height: 1280
            anchors.centerIn: parent
            rotation: 90
            gradient: Gradient {
                GradientStop { position: 0.0; color: valueSource.light }
                GradientStop { position: 0.4; color: "white" }
                GradientStop { position: 0.6; color: "white" }
                GradientStop { position: 1.0; color: valueSource.light }
            }
        }

        // Display a logo image
        Image {
            source: "../image/logo.png"
            width: 300
            height: 300
            fillMode: Image.PreserveAspectFit
            anchors.horizontalCenter: parent.horizontalCenter
            y: 10
        }

        // Create a circular gauge for speed
        CircularGauge {
            value: valueSource.speed
            maximumValue: 450
            width: 350
            height: 350
            x: parent.width / 2 - width / 2 - 420
            y: parent.height / 2 - height / 2 + 30

            style: SpeedGaugeStyle {}
        }

        // Create a circular gauge for RPM
        CircularGauge {
            value: valueSource.rpm
            maximumValue: 450
            width: 350
            height: 350
            x: parent.width / 2 - width / 2 + 420
            y: parent.height / 2 - height / 2 + 30

            style: RPMGaugeStyle {}
        }

        // Create a circular gauge for battery
        CircularGauge {
            value: valueSource.battery
            maximumValue: 100
            width: 150
            height: 150
            anchors.horizontalCenter: parent.horizontalCenter
            y: 315

            style: BatteryGaugeStyle {
                icon: "../image/battery-icon.png"
                tickmarkLabel: Text {}
            }
        }

        // Display gear-related text labels
        Text {
            text: "E                   F"
            font.family: font.name
            font.pixelSize: 15
            color: "black"
            x: parent.width / 2 - width / 2 + 1
            y: 340
        }

        // Display gear labels
        Text {
            text: "P"
            font.family: font.name
            font.pixelSize: 70
            color: (valueSource.gear === 0) ? "black" : "lightgray"
            x: parent.width / 2 - width / 2 - 180
            y: 180
        }

        Text {
            text: "D"
            font.family: font.name
            font.pixelSize: 70
            color: (valueSource.gear === 3) ? "black" : "lightgray"
            x: parent.width / 2 - width / 2 + 190
            y: 180
        }

        Text {
            text: "R"
            font.family: font.name
            font.pixelSize: 70
            color: (valueSource.gear === 1) ? "#FF6868" : "#FFCECE"
            x: parent.width / 2 - width / 2 - 140
            y: 250
        }

        Text {
            text: "N"
            font.family: font.name
            font.pixelSize: 70
            color: (valueSource.gear === 2) ? "#35CA3D" : "#AEFFAE"
            x: parent.width / 2 - width / 2 + 150
            y: 250
        }

        // Display left and right turn signal indicators
        Image {
            source: "../image/turn-icon.png"
            width: 60
            height: 60
            rotation: -90
            fillMode: Image.PreserveAspectFit
            x: parent.width / 2 - width / 2 - 180
            y: 30
            opacity: (valueSource.left_on_off) ? 1.0 : 0.2
        }

        Image {
            source: "../image/turn-icon.png"
            width: 60
            height: 60
            rotation: 90
            fillMode: Image.PreserveAspectFit
            x: parent.width / 2 - width / 2 + 180
            y: 30
            opacity: (valueSource.right_on_off) ? 1.0 : 0.2
        }
    }
}
