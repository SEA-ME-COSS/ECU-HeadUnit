import QtQuick 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

// Define a BasicGaugeStyle
BasicGaugeStyle {
    // Set the range of values (angle) for the gauge
    minimumValueAngle: -135
    maximumValueAngle: 135

    // Define tickmark properties
    tickmarkStepSize: 25       // The step size between major tickmarks
    minorTickmarkCount: 4     // Number of minor tickmarks between major ones

    // Define label properties
    labelStepSize: 50         // The step size between labels
    labelInset: 45            // Inset of labels from the gauge

    // Define properties for the gauge needle
    needleLength: 165         // Length of the gauge needle
    needleBaseWidth: 10       // Width of the base of the needle
    needleTipWidth: 1         // Width of the tip of the needle

    // Define the appearance of major tickmarks
    tickmark: Rectangle {
        implicitWidth: 3       // Width of the major tickmarks
        antialiasing: true     // Enable antialiasing for smoother rendering
        implicitHeight: 15     // Height of the major tickmarks
        color: "black"        // Color of the major tickmarks
    }

    // Define the appearance of minor tickmarks
    minorTickmark: Rectangle {
        implicitWidth: 2       // Width of the minor tickmarks
        antialiasing: true     // Enable antialiasing for smoother rendering
        implicitHeight: 7      // Height of the minor tickmarks
        color: "black"        // Color of the minor tickmarks
    }

    // Define the background of the gauge using a Canvas
    background: Canvas {
        FontLoader {
            id: font
            source: "../font/Nebula-Regular.otf"  // Load a custom font
        }

        // Display the RPM value
        Text {
            text: valueSource.rpm    // Bind to the 'rpm' valueSource property
            color: "black"           // Text color
            font.family: font.name   // Set the custom font
            font.pixelSize: 80       // Text size
            anchors.horizontalCenter: parent.horizontalCenter  // Center horizontally
            y: 170                   // Vertical position
        }
        // Display the label "RPM"
        Text {
            text: "RPM"              // Static label text
            color: "black"           // Text color
            font.family: font.name   // Set the custom font
            font.pixelSize: 30       // Text size
            anchors.horizontalCenter: parent.horizontalCenter  // Center horizontally
            y: 240                   // Vertical position
        }
    }
}
