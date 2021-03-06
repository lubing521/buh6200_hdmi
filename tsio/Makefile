###############################################################################
# export variables
###############################################################################
ifneq ($(srctree),)
    KERNEL_DIR := $(srctree)

    SDK_DIR := $(shell cd $(KERNEL_DIR)/../../../.. && /bin/pwd)
else
    SDK_DIR := $(shell cd $(CURDIR)/../../../.. && /bin/pwd)
endif

include $(SDK_DIR)/base.mak

###############################################################################
# local variables
###############################################################################

## header search path

EXTRA_CFLAGS += -I$(DRV_DIR)/include \
                -I$(DRV_DIR)/common/include

ifdef CFG_HI_TSIO_PHY_LOOPBACK_SUPPORT
EXTRA_CFLAGS += -DTSIO_PHY_LOOPBACK_SUPPORT
else
EXTRA_CFLAGS += -DTSIO_PHY_12MHZ_OFFSET=6 -DTSIO_PHY_12MHZ_SWING=4 -DTSIO_PHY_12MHZ_PRE_EMPHASIS=0 \
                -DTSIO_PHY_12MHZ_SLEW=3 -DTSIO_PHY_12MHZ_SKEW=0

EXTRA_CFLAGS += -DTSIO_PHY_25MHZ_OFFSET=6 -DTSIO_PHY_25MHZ_SWING=4 -DTSIO_PHY_25MHZ_PRE_EMPHASIS=0 \
                -DTSIO_PHY_25MHZ_SLEW=3 -DTSIO_PHY_25MHZ_SKEW=0

EXTRA_CFLAGS += -DTSIO_PHY_50MHZ_OFFSET=6 -DTSIO_PHY_50MHZ_SWING=4 -DTSIO_PHY_50MHZ_PRE_EMPHASIS=0 \
                -DTSIO_PHY_50MHZ_SLEW=3 -DTSIO_PHY_50MHZ_SKEW=1

EXTRA_CFLAGS += -DTSIO_PHY_100MHZ_OFFSET=6 -DTSIO_PHY_100MHZ_SWING=4 -DTSIO_PHY_100MHZ_PRE_EMPHASIS=0 \
                -DTSIO_PHY_100MHZ_SLEW=2 -DTSIO_PHY_100MHZ_SKEW=0
endif

ifdef CFG_HI_PROC_SUPPORT
    EXTRA_CFLAGS += -DTSIO_PROC_SUPPORT
endif

EXTRA_CFLAGS += $(CFG_HI_KMOD_CFLAGS)

MOD_NAME := hi_tsio

$(MOD_NAME)-y   :=  drv_tsio_intf.o        \
                    drv_tsio.o             \
                    drv_tsio_func.o        \
                    drv_tsio_utils.o       \
                    hal_tsio.o

###############################################################################
obj-$(HI_DRV_BUILDTYPE) += $(MOD_NAME).o

BUILD_DIR := $(HI_OUT_DIR)/$(OBJ_NAME)/$(subst $(SDK_DIR)/,,$(CURDIR))

BUILD_DIR_MAKEFILE := $(BUILD_DIR)/Makefile

#===============================================================================
#   rules
#===============================================================================
.PHONY: all clean

all: $(BUILD_DIR_MAKEFILE)
	$(AT)make -C $(LINUX_DIR) ARCH=$(CFG_HI_CPU_ARCH) CROSS_COMPILE=$(HI_KERNEL_TOOLCHAINS_NAME)- M=$(BUILD_DIR) src=$(CURDIR) modules
	$(AT)$(HI_KERNEL_TOOLCHAINS_NAME)-strip --strip-unneeded $(BUILD_DIR)/$(MOD_NAME).ko
	$(AT)test -d $(HI_MODULE_DIR) || mkdir -p $(HI_MODULE_DIR)
	$(AT)cp -f $(BUILD_DIR)/$(MOD_NAME).ko $(HI_MODULE_DIR)/

clean:
	$(AT)make -C $(LINUX_DIR) ARCH=$(CFG_HI_CPU_ARCH) CROSS_COMPILE=$(HI_KERNEL_TOOLCHAINS_NAME)- M=$(BUILD_DIR) src=$(CURDIR) clean
	$(AT)rm -rf $(HI_MODULE_DIR)/$(MOD_NAME).ko

$(BUILD_DIR_MAKEFILE): $(BUILD_DIR)
	$(AT)touch $@

$(BUILD_DIR):
	$(AT)mkdir -p $@
