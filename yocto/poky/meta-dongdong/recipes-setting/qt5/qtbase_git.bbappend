SUMMARY = "bitbake-layers recipe"
DESCRIPTION = "Recipe created by bitbake-layers"
LICENSE = "CLOSED"
 
PACKAGECONFIG:append = " eglfs fontconfig gles2"
DEPENDS += "userland"

