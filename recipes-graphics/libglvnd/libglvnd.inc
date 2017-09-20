SUMMARY = "The GL Vendor-Neutral Dispatch library"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI = " \
	git://github.com/NVIDIA/libglvnd.git;protocol=https \
	file://0000-egl-pkgconfig.patch \
"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://README.md;md5=ecb4629295de7c908bb3717e01494be7"

S = "${WORKDIR}/git"

DEPENDS = "python libx11 libxext glproto"

inherit autotools pkgconfig

PROVIDES = "virtual/libgl virtual/libgles1 virtual/libgles2 virtual/egl virtual/mesa"
RPROVIDES_${PN} = "libgl libgles1 libgles2 libegl egl xserver-xorg-extension-glx"

do_install_append() {
	mkdir -p ${D}${includedir}
	cp -r ${S}/include/GL ${D}${includedir}/
	cp -r ${S}/include/KHR ${D}${includedir}/
	cp -r ${S}/include/EGL ${D}${includedir}/
	cp -r ${S}/include/GLES ${D}${includedir}/
	cp -r ${S}/include/glvnd ${D}${includedir}/
	cp -r ${S}/include/glheader.h ${D}${includedir}/
}
