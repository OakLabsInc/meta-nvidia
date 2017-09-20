# The opengl deps force xserver-xorg to depend on virtual/mesa, which
# we want to avoid because we're using libglvnd

PACKAGECONFIG_remove = "${OPENGL_PKGCONFIGS}"
