SUMMARY = "Basic image for HeadUnit"
LICENSE = "CLOSED"

inherit dongdong-rpi-image

LINGUAS_KO_KR = "ko-kr"
LINGUAS_EN_US = "en-us"
IMAGE_LIGUAS = "${LINGUAS_KO_KR} ${LINGUAS_EN_US}"
IMAGE_OVERHEAD_FACTOR = "1.3"


inherit extrausers

EXTRA_USERS_PARAMS = " \
                      groupadd seame; \
                      useradd -p \$(openssl passwd 1234) team5; \
                      useradd -a -G sudo team5; \
                      useradd -g seame team5; \
"

