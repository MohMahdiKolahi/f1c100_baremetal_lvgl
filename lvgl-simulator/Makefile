#
# Project makefile
#

PROJECT_NAME = LVGL_demo

BASE_DIR = base
PRJ_DIR := ..

# link file
LINK_SCRIPT = $(BASE_DIR)/f1c100s_dram.ld


# source files
SRCS += \
	src/system.c \
	src/exception.c \
	main.c \
	src/display.c \
	src/lv_demo_widgets.c \
	$(GEN_CSRCS)
	
INCLUDES += -I. -Iinc
INCLUDES += -I$(LVGL_DIR)

# Define optimisation level here
OPT = -Os

# include sub makefiles
LVGL_DIR		= ..
LVGL_DIR_NAME	= lvgl
include $(LVGL_DIR)/lvgl/lvgl.mk
include $(PRJ_DIR)/generated/generated.mk
include $(PRJ_DIR)/custom/custom.mk

SRCS += $(CSRCS)

DEFS += -DLOAD_HEADER # add header for simple_loader

include base/f1c100s_common.mk
