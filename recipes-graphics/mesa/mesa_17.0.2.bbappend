PACKAGECONFIG[glvnd] = "--enable-libglvnd,--disable-libglvnd,libglvnd"
PACKAGECONFIG_append = " glvnd"

PACKAGES_append += " libglx-mesa libglx-mesa-dev"
PACKAGES_remove = "libgl-mesa libgl-mesa-dev libegl-mesa libegl-mesa-dev libgles1-mesa libgles1-mesa-dev libgles2-mesa libgles2-mesa-dev"

PROVIDES_remove = "virtual/libgl virtual/libgles1 virtual/libgles2 virtual/egl virtual/mesa"

# We ONLY want glx
do_install_append() {
	rm -rf ${D}${includedir}/GL
	rm -rf ${D}${includedir}/GLES
	rm -rf ${D}${includedir}/KHR
	rm -rf ${D}${includedir}/EGL
	rm -rf ${D}${includedir}/GLES2
	rm -f ${D}${libdir}/pkgconfig/gl.pc
	rm -f ${D}${libdir}/pkgconfig/egl.pc
	rm -f ${D}${libdir}/pkgconfig/glesv1_cm.pc
	rm -f ${D}${libdir}/pkgconfig/glesv2.pc
	rm -f ${D}${libdir}/libEGL.so
	rm -f ${D}${libdir}/libGLESv1_CM.so
	rm -f ${D}${libdir}/libGLESv2.so
}

FILES_libglx-mesa_append = " \
	${libdir}/libGLX_mesa.so.0.0.0 \
"

FILES_libglx-mesa-dev_append = " \
	${libdir}/libGLX_mesa.so.0 \
	${libdir}/libGLX_mesa.so \
"
RDEPENDS_libglx-mesa-dev_append = " libglx-mesa"
