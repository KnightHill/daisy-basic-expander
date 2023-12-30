# Project Name
TARGET = BasicExpander

LDFLAGS = -u _printf_float

# Sources
CPP_SOURCES = main.cpp basic_exp.cpp

# Library Locations
LIBDAISY_DIR = ../../libDaisy
DAISYSP_DIR = ../../DaisySP

# Core location, and generic Makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile

