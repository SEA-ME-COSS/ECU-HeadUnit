SUMMARY = "CircuitPython APIs for non-CircuitPython versions of Python such as CPython on Linux and MicroPython."
HOMEPAGE = "https://github.com/adafruit/Adafruit_Blinka"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=fccd531dce4b989c05173925f0bbb76c"

SRC_URI = "git://github.com/adafruit/Adafruit_Blinka.git;branch=main;protocol=https"
SRCREV = "b50846d4207dbea6ac5dc2d22bce5c98f97092b9"

S = "${WORKDIR}/git"

RDEPENDS:${PN} += " \
        libgpiod \
        python3-adafruit-platformdetect \
        python3-adafruit-pureio \
        python3-core \
"

do_delete_files() {
    rm ${S}/src/adafruit_blinka/microcontroller/bcm283x/pulseio/libgpiod_pulsein
    rm ${S}/src/adafruit_blinka/microcontroller/bcm283x/pulseio/libgpiod_pulsein.license
    rm ${S}/src/adafruit_blinka/microcontroller/amlogic/a311d/pulseio/libgpiod_pulsein
    rm ${S}/src/adafruit_blinka/microcontroller/amlogic/a311d/pulseio/libgpiod_pulsein.license
}

addtask do_delete_files after do_patch before do_configure

do_install() {
    install -d ${D}${libdir}/python3.10/site-packages/
    cp -R ${WORKDIR}/git/src/* ${D}${libdir}/python3.10/site-packages/
}

FILES:${PN} += "${libdir}/python3.10/site-packages"

COMPATIBLE_HOST:libc-musl:class-target = "null"
