SUMMARY = "Simple wrapper for docker-compose to use GPU enabled docker under nvidia-docker"
HOMEPAGE = "https://github.com/eywalker/nvidia-docker-compose"
LICENSE = "MIT"

SRC_URI = "git://github.com/eywalker/nvidia-docker-compose.git;protocol=https"
S = "${WORKDIR}/git"

RDEPENDS_${PN} += " nvidia-docker"

inherit setuptools
