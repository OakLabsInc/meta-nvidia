FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI_append = " file://nvidia.conf"

do_install_append() {
	install -m 0644 -D ${WORKDIR}/nvidia.conf ${D}${sysconfdir}/X11/xorg.conf.d/nvidia.conf
}
