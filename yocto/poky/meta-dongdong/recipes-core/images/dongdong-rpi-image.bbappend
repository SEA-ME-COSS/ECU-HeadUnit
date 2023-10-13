IMAGE_BASE = " \
    python3 \
    python3-numpy \
    bash \
    openssh \
    wpa-supplicant \
    git \
    can-utils \
    libsocketcan \
    bcm2835-dev \
"

EX_CODE = " \
    helloworld \
    simple \
    vsomeip-test \
"

VSOMEIP_PKGS = " \
    common-api-c++ \
    common-api-c++-dev \
    vsomeip \
    vsomeip-dev \
    common-api-c++-someip \
    common-api-c++-someip-dev \
"

HU_CODE = " \
    headunit-test \
"

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
    qtquickcontrols \
    qtquickcontrols-dev \
    qtquickcontrols-mkspecs \
    qtquickcontrols2 \
    qtmultimedia \
"

PIRACER_PKGS = " \
    python-adafruit-blinka \
    python-adafruit-circuitpython-busdevice \
    python3-adafruit-circuitpython-pca9685 \
    python3-adafruit-circuitpython-register \
    python3-adafruit-platformdetect \
    python3-adafruit-pureio \
    python3-pyserial \
    python3-pyusb \
    rpi-gpio \
    python3-typing-extensions \
    python3-wheel \
    python-adafruit-circuitpython-framebuf \
    python-adafruit-circuitpython-ina219 \
    python-adafruit-circuitpython-ssd1306 \
    python-adafruit-circuitpython-typing \
    python-adafruit-circuitpython-requests \
    python-pyftdi \
    python-piracer-py \
"

IMAGE_INSTALL += " \
    ${IMAGE_BASE} \
    ${QT_BASE} \
    ${QT_PKGS} \
    ${PIRACER_PKGS} \
    ${HU_CODE} \
    ${EX_CODE} \
    ${VSOMEIP_PKGS} \
"

