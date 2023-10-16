SUMMARY = "Auto start the qt5 application"

LICENSE = "CLOSED"

SRC_URI = "file://auto-start.sh \
           file://auto-start.service"

S = "${WORKDIR}"

#do_install() {
#    install -d ${D}${sysconfdir}/profile.d
#    install -m 0755 ${WORKDIR}/auto-start.sh ${D}${sysconfdir}/profile.d/auto-start.sh
#}

#FILES:{PN} = "${sysconfdir}"


do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/auto-start.sh ${D}${bindir}/auto-start.sh
    
    install -d ${D}${systemd_system_unitdir}
    install -m 0644 ${WORKDIR}/auto-start.service ${D}${systemd_system_unitdir}
}

FILES:${PN} = "${bindir}/auto-start.sh \
               ${systemd_system_unitdir}/auto-start.service"

inherit systemd

SYSTEMD_PACKAGES = "${PN}"
SYSTEMD_SERVICE_${PN} = "auto-start.service"
SYSTEMD_AUTO_ENABLE_${PN} = "enable"

