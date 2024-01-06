#
# global definitions
PROJECT_NAME = oracle
ifeq (, $(PROJECTS_BASE))
PROJECT_BASE = ${HOME}/projects/${PROJECT_NAME}
else
PROJECT_BASE = ${PROJECTS_BASE}/${PROJECT_NAME}
endif

PROJECT_BIN_DIR = $(PROJECT_BASE)/bin
PROJECT_INCLUDE_DIR = $(PROJECT_BASE)/include

LISTC_INTERFACE_DIR = $(PROJECT_INCLUDE_DIR)/listc

ifeq (TRUE, $(SHOWINFO))
$(info LISTC_INTERFACE_DIR="$(LISTC_INTERFACE_DIR)")
endif

##
#global (common) settings
SHELL = /bin/sh
CC = gcc
#CC = g++-11

DEFS =  -DLINUX=1
CFLAGSDEBUG = -O0 -g3 -fmessage-length=0 -MMD -MP -fprofile-arcs -ftest-coverage 
CFLAGSRELEASE = -O0 -g3 -fmessage-length=0 -MMD -MP 

$(info DEBUG="$(DEBUG)")
ifeq (TRUE, $(DEBUG))
CFLAGSTOUSE = $(CFLAGSDEBUG)
else
CFLAGSTOUSE = $(CFLAGSRELEASE)
endif
$(info CFLAGSTOUSE="$(CFLAGSTOUSE)")

