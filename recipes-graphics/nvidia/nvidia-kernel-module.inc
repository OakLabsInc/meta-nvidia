inherit module
do_compile[depends] += "virtual/kernel:do_shared_workdir"
EXTRA_OEMAKE_append = " SYSSRC=${STAGING_KERNEL_DIR} KERNEL_OUTPUT=${STAGING_KERNEL_BUILDDIR}"
