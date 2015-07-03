#
# Copyright 2014, NICTA
#
# This software may be distributed and modified according to the terms of
# the BSD 2-Clause license. Note that NO WARRANTY is provided.
# See "LICENSE_BSD2.txt" for details.
#
# @TAG(NICTA_BSD)
#

TARGETS          := libsel4.a

# Source files required to build the target
CFILES := \
	$(patsubst $(SOURCE_DIR)/%,%,$(wildcard $(SOURCE_DIR)/src/*.c)) \
	$(patsubst $(SOURCE_DIR)/%,%,$(wildcard $(SOURCE_DIR)/src/${ARCH}/*.c))

ASMFILES := \
	$(patsubst $(SOURCE_DIR)/%,%,$(wildcard $(SOURCE_DIR)/src/*.S)) \
	$(patsubst $(SOURCE_DIR)/%,%,$(wildcard $(SOURCE_DIR)/src/${ARCH}/*.S))

# Header files/directories this library provides
# Note: sel4_client.h may not have been built at the time this is evaluated.
#HDRFILES := \
#	$(BUILD_DIR)/include/sel4 \
#	$(BUILD_DIR)/include/interfaces  #TODO proper prefix instruction

libs := sel4_gen sel4_halt

.DEFAULT_GOAL := default

include $(SEL4_COMMON)/common.mk