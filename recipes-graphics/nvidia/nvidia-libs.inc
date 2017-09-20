# Jesus fuck, this is complicated.
# Read this first: https://devtalk.nvidia.com/default/topic/915640/unix-graphics-announcements-and-news/multiple-glx-client-libraries-in-the-nvidia-linux-driver-installer-package/

do_install_append() {
	mkdir -p ${D}${libdir}/xorg/modules/drivers \
	         ${D}${libdir}/xorg/modules/extensions

	cp ${NVIDIA_SRC}/libEGL_nvidia.so.${PV} ${D}${libdir}/
	ln -sf libEGL_nvidia.so.${PV} ${D}${libdir}/libEGL_nvidia.so.0
	cp ${NVIDIA_SRC}/libGLESv1_CM_nvidia.so.${PV} ${D}${libdir}/
	ln -sf libGLESv1_CM_nvidia.so.${PV} ${D}${libdir}/libGLESv1_CM_nvidia.so.1
	cp ${NVIDIA_SRC}/libGLESv2_nvidia.so.${PV} ${D}${libdir}/
	ln -sf libGLESv2_nvidia.so.${PV} ${D}${libdir}/libGLESv2_nvidia.so.2
	cp ${NVIDIA_SRC}/libGLX_nvidia.so.${PV} ${D}${libdir}/
	ln -sf libGLX_nvidia.so.${PV} ${D}${libdir}/libGLX_nvidia.so.0
	ln -sf libGLX_nvidia.so.${PV} ${D}${libdir}/libGLX_indirect.so.0

	cp ${NVIDIA_SRC}/tls/libnvidia-tls.so.${PV} ${D}${libdir}/
	cp ${NVIDIA_SRC}/libnvidia-glcore.so.${PV} ${D}${libdir}/
	cp ${NVIDIA_SRC}/libnvidia-eglcore.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-ml.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-fbc.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-ifr.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-glsi.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-encode.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-opencl.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-compiler.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-ptxjitcompiler.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-cfg.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-gtk2.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-gtk3.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-wfb.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvidia-fatbinaryloader.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libcuda.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libnvcuvid.so.${PV} ${D}${libdir}/
    cp ${NVIDIA_SRC}/libvdpau_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libvdpau_nvidia.so.${PV} ${D}${libdir}/libvdpau_nvidia.so

    # xf86-video-nvidia
	cp -r ${NVIDIA_SRC}/nvidia_drv.so ${D}${libdir}/xorg/modules/drivers/
	cp -r ${NVIDIA_SRC}/libglx.so.${PV} ${D}${libdir}/xorg/modules/extensions/libglx.so

    # nvidia
	mkdir -p ${D}${bindir}
    install -m 755 -D ${NVIDIA_SRC}/nvidia-settings ${D}${bindir}/nvidia-settings
    install -m 755 -D ${NVIDIA_SRC}/nvidia-debugdump ${D}${bindir}/nvidia-debugdump
    install -m 755 -D ${NVIDIA_SRC}/nvidia-smi ${D}${bindir}/nvidia-smi
    install -m 755 -D ${NVIDIA_SRC}/nvidia-modprobe ${D}${bindir}/nvidia-modprobe
    install -m 755 -D ${NVIDIA_SRC}/nvidia-xconfig ${D}${bindir}/nvidia-xconfig
    install -m 755 -D ${NVIDIA_SRC}/nvidia-cuda-mps-server ${D}${bindir}/nvidia-cuda-mps-server
    install -m 755 -D ${NVIDIA_SRC}/nvidia-cuda-mps-control ${D}${bindir}/nvidia-cuda-mps-control
    install -m 755 -D ${NVIDIA_SRC}/nvidia-persistenced ${D}${bindir}/nvidia-persistenced

    # nvidia-doc
	mkdir -p ${D}${datadir}/doc/nvidia ${D}${mandir}/man1
    cp -r ${NVIDIA_SRC}/html ${D}${datadir}/doc/nvidia/
    cp ${NVIDIA_SRC}/NVIDIA_Changelog ${D}${datadir}/doc/nvidia/
    cp ${NVIDIA_SRC}/README.txt ${D}${datadir}/doc/nvidia/
    install -m 444 -D ${NVIDIA_SRC}/nvidia-settings.1.gz ${D}${mandir}/man1/nvidia-settings.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-smi.1.gz ${D}${mandir}/man1/nvidia-smi.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-xconfig.1.gz ${D}${mandir}/man1/nvidia-xconfig.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-cuda-mps-control.1.gz ${D}${mandir}/man1/nvidia-cuda-mps-control.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-persistenced.1.gz ${D}${mandir}/man1/nvidia-persistenced.1.gz
}

python populate_packages_prepend() {
    d.appendVar("RDEPENDS_nvidia", " xorg-abi-video-23")
}

do_make_scripts[noexec] = "1"

REQUIRED_DISTRO_FEATURES = "x11"

FILES_${PN} += " \
	${libdir} \
	${bindir} \
"

FILES_${PN}-doc += " \
	${mandir} \
	${datadir}/doc/nvidia \
"

RDEPENDS_${PN} += " \
	xserver-xorg-module-libwfb \
    libvdpau \
"

INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
INHIBIT_PACKAGE_STRIP = "1"
INSANE_SKIP_${PN}_append = "ldflags already-stripped"
INSANE_SKIP_libgl-nvidia_append = "ldflags"
