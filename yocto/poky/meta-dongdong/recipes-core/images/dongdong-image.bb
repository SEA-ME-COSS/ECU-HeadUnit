SUMMARY = "A basic Qt5 dev image"
 
include recipes-core/images/rpi-test-image.bb

inherit populate_sdk populate_sdk_qt5

QT_BASE = " \
    qtbase \
    qtbase-dev \
    qtbase-mkspecs \
    qtbase-plugins \
    qtbase-tools \
"
 
QT_PKGS = " \
    qt3d \
    qt3d-dev \
    qt3d-mkspecs \
    qtcharts \
    qtcharts-dev \
    qtcharts-mkspecs \
    qtconnectivity-dev \
    qtconnectivity-mkspecs \
    qtquickcontrols2 \
    qtquickcontrols2-dev \
    qtquickcontrols2-mkspecs \
    qtdeclarative \
    qtdeclarative-dev \
    qtdeclarative-mkspecs \
    qtgraphicaleffects \
    qtgraphicaleffects-dev \
"
 
IMAGE_INSTALL += " \
    ${QT_BASE} \
    ${QT_PKGS} \
    simple \
    "

IMAGE_INSTALL:append = " bash python3 python3-numpy"

