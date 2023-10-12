SUMARRY = "Tlqkf"
LICENSE = "CLOSED"

SRC_URI = "file://can-test.cpp"

S = "${WORKDIR}"

do_compile() {
    ${CXX} ${LDFLAGS} can-test.cpp -o can-test
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 can-test ${D}${bindir}
}

