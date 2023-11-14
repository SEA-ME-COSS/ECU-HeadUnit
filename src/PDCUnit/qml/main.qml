import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.4
import QtMultimedia 5.15

Window {
    id: root
    title: "PDC Unit"
    width: 1024
    height: 600
    visible: true

    FontLoader {
        id: font
        source: "../font/Nebula-Regular.otf"
    }

    Item {
        id: container
        width: 1024
        height: 600
        anchors.centerIn: parent

        // transform: Scale {
        //     xScale: -1
        //     origin.x: parent.width / 2
        // }

        Camera {
            id: camera
            objectName: "camera"
            captureMode: Camera.CaptureViewfinder
        }

        VideoOutput {
            id: viewfinder
            objectName: "viewfinder"
            source: camera
            anchors.fill: parent
        }

        Rectangle {
            color: "white"
            opacity: 0.5
            anchors.fill: parent
        }

        Text {
            text: "Parking Distance Control"
            font.family: font.name
            font.pixelSize: 40
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
            y: 30
        }
    }
}


// //////////////////////

//         // parking distance control content display (visible when in R gear mode)
//         Rectangle {
//             visible: (valueSource.gear === 1)
//             width: 675
//             height: 600
//             color: "#555555"
//             anchors.centerIn: parent

//             Text {
//                 text: "Parking Distance Control"
//                 font.family: font.name
//                 font.pixelSize: 30
//                 color: "white"
//                 anchors.horizontalCenter: parent.horizontalCenter
//                 y: 30
//             }

//             Image {
//                 source: "../image/pdc_path_straight.png"
//                 width: 675
//                 height: 675
//                 fillMode: Image.PreserveAspectFit
//                 anchors.centerIn: parent
//             }

//             Image {
//                 source: "../image/pdc_car.png"
//                 width: 675
//                 height: 675
//                 fillMode: Image.PreserveAspectFit
//                 anchors.centerIn: parent
//             }

//             Image {
//                 source: "../image/pdc_red_indicator.png"
//                 visible: (carinfo.distance < 10)
//                 width: 675
//                 height: 675
//                 fillMode: Image.PreserveAspectFit
//                 anchors.centerIn: parent
//             }

//             Image {
//                 source: "../image/pdc_yellow_indicator.png"
//                 visible: (carinfo.distance < 20)
//                 width: 675
//                 height: 675
//                 fillMode: Image.PreserveAspectFit
//                 anchors.centerIn: parent
//             }

//             Image {
//                 source: "../image/pdc_green_indicator.png"
//                 visible: (carinfo.distance < 30)
//                 width: 675
//                 height: 675
//                 fillMode: Image.PreserveAspectFit
//                 anchors.centerIn: parent
//             }
//         }