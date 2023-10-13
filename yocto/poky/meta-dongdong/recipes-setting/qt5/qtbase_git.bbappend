SUMMARY = "Add Qt pkgs needed"

PACKAGECONFIG:append = " eglfs fontconfig gles2 linuxfb tslib accessibility"
DEPENDS += "userland"

