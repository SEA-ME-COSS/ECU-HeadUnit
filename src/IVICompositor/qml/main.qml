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
            }

            Item {
                id: headUnitArea
                width: 1024
                height: 600
                anchors.centerIn: parent
                z: (carinfo.gear === 1 ? 0 : 1)
            }

            Item {
                id: pdcUnitArea
                width: 512
                height: 600
                anchors.centerIn: parent
                color: "white"
                z: (carinfo.gear === 1 ? 1 : 0)
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
