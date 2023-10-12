DESCRIPTION = "WiringPi Library with Autotools"
LICENSE = "CLOSED"

SRC_URI = "file://wiringpi/"
S = "${WORKDIR}/wiringpi"

DEPENDS += "ldconfig-native libxcrypt"

do_compile() {
    # WiringPi Library
    cd ${S}/wiringPi
    oe_runmake -j5

    # WiringPi Devices Library
# cd ${S}/devLib
#   oe_runmake -j5

    # GPIO Utility
#   cd ${S}/gpio
#   oe_runmake -j5
}

do_install() {
    # WiringPi Library
    cd ${S}/wiringPi
    oe_runmake install DESTDIR=${D}

    # WiringPi Devices Library
#   cd ${S}/devLib
#   oe_runmake install DESTDIR=${D}

    # GPIO Utility
#    cd ${S}/gpio
#   oe_runmake install DESTDIR=${D}
}

