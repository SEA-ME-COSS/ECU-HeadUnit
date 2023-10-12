SUMMARY = "fejai"
LICENSE = "CLOSED"

SRC_URI = " \
            file://CMakeLists.txt \
            file://reboot_script \
            file://src \
            file://src-gen-desproject \
"

S = "${WORKDIR}"

inherit cmake_qt5

DEPENDS = " common-api-c++ vsomeip common-api-c++-someip qtbase qtquickcontrols2 qtmultimedia python3 qtbase-native"

