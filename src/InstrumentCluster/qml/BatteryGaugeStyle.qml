import QtQuick 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

// Define a BasicGaugeStyle
BasicGaugeStyle {
    // Set the range of values (angle) for the gauge
    minimumValueAngle: -60
    maximumValueAngle: 60

    // Define tickmark properties
    tickmarkStepSize: 25       // The step size between major tickmarks
    minorTickmarkCount: 4     // Number of minor tickmarks between major ones

    // Define properties for the gauge needle
    needleLength: 70          // Length of the gauge needle
    needleBaseWidth: 5       // Width of the base of the needle
    needleTipWidth: 1         // Width of the tip of the needle

    halfGauge: true           // Configure the gauge as a half-gauge

    property string icon: ""  // A property to specify an icon image

    // Define the appearance of major tickmarks
    tickmark: Rectangle {
        implicitWidth: 2       // Width of the major tickmarks
        antialiasing: true     // Enable antialiasing for smoother rendering
        implicitHeight: 10    // Height of the major tickmarks
        color: "black"        // Color of the major tickmarks
    }

    // Define the appearance of minor tickmarks
    minorTickmark: Rectangle {
        implicitWidth: 1       // Width of the minor tickmarks
        antialiasing: true     // Enable antialiasing for smoother rendering
        implicitHeight: 5     // Height of the minor tickmarks
        color: "black"        // Color of the minor tickmarks
    }

    // Define the background of the gauge
    background: Item {
        Image {
            source: icon          // Set the image source from the 'icon' property
            width: 70             // Width of the image
            height: 70            // Height of the image
            fillMode: Image.PreserveAspectFit  // Preserve aspect ratio of the image
            anchors.horizontalCenter: parent.horizontalCenter  // Center the image horizontally
            y: 13                // Vertical position of the image
        }
    }
}
