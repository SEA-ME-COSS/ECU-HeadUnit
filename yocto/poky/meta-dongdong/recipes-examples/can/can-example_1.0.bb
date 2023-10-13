SUMARRY = "Basic test code for CAN communication"
LICENSE = "CLOSED"

SRC_URI = "file://can-example.cpp"

S = "${WORKDIR}"

do_compile() {
    ${CXX} ${LDFLAGS} can-test.cpp -o can-test
}

do_install() {
    install -d ${D}${bindir}/example
    install -m 0755 can-test ${D}${bindir}/example/
}

