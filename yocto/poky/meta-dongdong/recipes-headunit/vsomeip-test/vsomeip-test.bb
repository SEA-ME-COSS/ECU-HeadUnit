SMARRY = "Tlqkf"
LICENSE = "CLOSED"

SRC_URI = " \
        file://CMakeLists.txt \
        file://src/ \
        file://src-gen-manager/ \
        "

S = "${WORKDIR}"

inherit cmake

DEPENDS = " common-api-c++ vsomeip common-api-c++-someip qtbase qtquickcontrols2"
RDEPENDS:{PN} += " common-api-c++ vsomeip common-api-c++-someip"

# EXTRA_OECMAKE += "-DCMAKE_INCLUDE_PATH=${STAGING_INCDIR} \
#                   -DCMAKE_LIBRARY_PATH=${STAGING_LIBDIR}"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${B}/RpmClient ${D}${bindir}
    install -m 0755 ${B}/SpeedClient ${D}${bindir}
    install -m 0755 ${B}/ManagerService ${D}${bindir}
}

FILES:${PN} += "${bindir}/RpmClient"
FILES:${PN} += "${bindir}/SpeedClient"
FILES:${PN} += "${bindir}/ManagerService"

