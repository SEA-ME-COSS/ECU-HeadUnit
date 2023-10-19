import QtQuick 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

// Define a custom gauge style based on BasicGaugeStyle
BasicGaugeStyle {
    // Set the minimum and maximum value angles for the gauge
    minimumValueAngle: -135
    maximumValueAngle: 135

    // Define properties related to tickmarks
    tickmarkStepSize: 25      // Step size between major tickmarks
    minorTickmarkCount: 4    // Number of minor tickmarks between major ones

    // Define properties for labels
    labelStepSize: 50        // Step size between labels
    labelInset: 45           // Inset of labels from the gauge

    // Define properties for the gauge needle
    needleLength: 165         // Length of the gauge needle
    needleBaseWidth: 10       // Width of the base of the needle
    needleTipWidth: 1         // Width of the tip of the needle

    // Define the appearance of major tickmarks
    tickmark: Rectangle {
        implicitWidth: 3       // Width of major tickmarks
        antialiasing: true     // Enable antialiasing for smoother rendering
        implicitHeight: 15     // Height of major tickmarks
        color: "black"        // Color of major tickmarks
    }

    // Define the appearance of minor tickmarks
    minorTickmark: Rectangle {
        implicitWidth: 2       // Width of minor tickmarks
        antialiasing: true     // Enable antialiasing for smoother rendering
        implicitHeight: 7      // Height of minor tickmarks
        color: "black"        // Color of minor tickmarks
    }

    // Define the background of the gauge using a Canvas
    background: Canvas {
        FontLoader {
            id: font
            source: "../font/Nebula-Regular.otf"  // Load a custom font
        }

        // Display the speed value
        Text {
            text: valueSource.speed   // Bind to the 'speed' valueSource property
            color: "black"           // Text color
            font.family: font.name   // Set the custom font
            font.pixelSize: 80       // Text size
            anchors.horizontalCenter: parent.horizontalCenter  // Center horizontally
            y: 170                   // Vertical position
        }
        // Display the label "mm/s"
        Text {
            text: "mm/s"              // Static label text
            color: "black"            // Text color
            font.family: font.name    // Set the custom font
            font.pixelSize: 30        // Text size
            anchors.horizontalCenter: parent.horizontalCenter  // Center horizontally
            y: 240                    // Vertical position
        }
    }
}
