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

#===============================================================================
# local variables
#===============================================================================
PQ_DIR := pq_v6_0
obj-y += $(PQ_DIR)/

#=================================================================
#     rules
#=================================================================
.PHONY: all clean

all:
	$(AT)make -C $(PQ_DIR) all

clean:
	$(AT)make -C $(PQ_DIR) clean

