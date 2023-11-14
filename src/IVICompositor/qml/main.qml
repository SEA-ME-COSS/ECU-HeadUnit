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
                width: 1024
                height: 600
                anchors.centerIn: parent
                color: "black"
                z: 0
            }

            Rectangle {
                id: headUnitArea
                width: 1024
                height: 600
                anchors.centerIn: parent
                z: (carinfo.gear === 1 ? 1 : 2)
            }

            Rectangle {
                id: pdcUnitArea
                width: 600
                height: 600
                anchors.centerIn: parent
                z: (carinfo.gear === 1 ? 2 : 1)
            }
        }
    }

    Component {
        id: chromeComponent
        ShellSurfaceItem {
            anchors.fill: parent
            onSurfaceDestroyed: destroy()
            //onWidthChanged: handleResized()
            //onHeightChanged: handleResized()
            //function handleResized() {
            //    shellSurface.sendConfigure(Qt.size(width, height));
            //}
        }
    }

    IviApplication {
        onIviSurfaceCreated: {
            var surfaceArea = iviSurface.iviId === 1110 ? pdcUnitArea : headUnitArea;
            var item = chromeComponent.createObject(surfaceArea, { "shellSurface": iviSurface } );
            //item.handleResized();
        }
    }
}
