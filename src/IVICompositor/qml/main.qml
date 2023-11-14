import QtQuick 2.2
import QtQuick.Window 2.1
import QtWayland.Compositor 1.0

WaylandCompositor {
    WaylandOutput {
        sizeFollowsWindow: true
        window: Window {
            width: 1024
            height: 600
            visible: true

            Rectangle {
                id: headUnitArea
                width: 500
                height: parent.height
                anchors.left: parent.left
                color: "cornflowerblue"
                Text {
                    anchors.centerIn: parent
                    text: "Ivi surface with id 1337"
                }
            }

            Rectangle {
                id: pdcUnitArea
                width: 500
                height: parent.height
                anchors.right: parent.right
                color: "burlywood"
                Text {
                    anchors.centerIn: parent
                    text: "Other surfaces"
                }
            }
        }
    }

    Component {
        id: chromeComponent
        ShellSurfaceItem {
            anchors.fill: parent
            onSurfaceDestroyed: destroy()
            onWidthChanged: handleResized()
            onHeightChanged: handleResized()
            function handleResized() {
                shellSurface.sendConfigure(Qt.size(width, height));
            }
        }
    }

    IviApplication {
        onIviSurfaceCreated: {
            var surfaceArea = iviSurface.iviId === 1111 ? pdcUnitArea : headUnitArea;
            var item = chromeComponent.createObject(surfaceArea, { "shellSurface": iviSurface } );
            item.handleResized();
        }
    }
}
