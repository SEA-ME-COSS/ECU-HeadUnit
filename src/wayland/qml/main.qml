import QtQuick 2.2
import QtQuick.Controls 1.4
import QtWayland.Compositor 1.15
import QtQuick.Window 2.1

WaylandCompositor {
    id: comp

    WaylandOutput {
        compositor: comp
        sizeFollowsWindow: true
        window: Window {
            visible: true
            width: 700
            height: 700
        }
    }
}
