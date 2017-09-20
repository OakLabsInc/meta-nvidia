SUMMARY = "NVidia Binary Graphics Driver"
LICENSE = "NVIDIA-Proprietary"
LIC_FILES_CHKSUM = "file://../LICENSE;md5=60ad17cc726658e8cf73578bea47b85f"

NVIDIA_ARCHIVE_NAME = "NVIDIA-Linux-${TARGET_ARCH}-${PV}"
NVIDIA_SRC = "${WORKDIR}/${NVIDIA_ARCHIVE_NAME}"

SRC_URI = " \
	https://us.download.nvidia.com/XFree86/Linux-${TARGET_ARCH}/${PV}/${NVIDIA_ARCHIVE_NAME}.run;downloadfilename=nvidia.run \
"

S = "${NVIDIA_SRC}/kernel"

do_unpack() {
	chmod +x ${DL_DIR}/nvidia.run
	rm -rf ${NVIDIA_SRC}
	${DL_DIR}/nvidia.run -x --target ${NVIDIA_SRC}
}

do_make_scripts[noexec] = "1"
