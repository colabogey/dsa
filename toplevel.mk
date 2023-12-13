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

ARRAYSHIFT_INTERFACE_DIR = $(PROJECT_INCLUDE_DIR)/array_shift
HASH_INTERFACE_DIR = $(PROJECT_INCLUDE_DIR)/hash
LIST_INTERFACE_DIR = $(PROJECT_INCLUDE_DIR)/list
TREE_INTERFACE_DIR = $(PROJECT_INCLUDE_DIR)/tree

ifeq (TRUE, $(SHOWINFO))
$(info PROJECT_BASE="$(PROJECT_BASE)")
$(info PROJECT_BIN_DIR="$(PROJECT_BIN_DIR)")
$(info PROJECT_INCLUDE_DIR="$(PROJECT_INCLUDE_DIR)")
$(info ARRAYSHIFT_INTERFACE_DIR="$(ARRAYSHIFT_INTERFACE_DIR)")
$(info HASH_INTERFACE_DIR="$(HASH_INTERFACE_DIR)")
$(info LIST_INTERFACE_DIR="$(LIST_INTERFACE_DIR)")
$(info TREE_INTERFACE_DIR="$(TREE_INTERFACE_DIR)")
endif

##
#global (common) settings
SHELL = /bin/sh
CC = g++
#CC = g++-11

DEFS =  -DLINUX=1
CFLAGSDEBUG = -std=c++20 -O0 -g3 -fmessage-length=0 -MMD -MP -fprofile-arcs -ftest-coverage -fpermissive
CFLAGSRELEASE = -std=c++20 -O0 -g3 -fmessage-length=0 -MMD -MP -fpermissive
#CFLAGSDEBUG = -std=c++17 -O0 -g3 -fmessage-length=0 -MMD -MP -fprofile-arcs -ftest-coverage
#CFLAGSRELEASE = -std=c++17 -O0 -g3 -fmessage-length=0 -MMD -MP

$(info DEBUG="$(DEBUG)")
ifeq (TRUE, $(DEBUG))
CFLAGSTOUSE = $(CFLAGSDEBUG)
else
CFLAGSTOUSE = $(CFLAGSRELEASE)
endif
$(info CFLAGSTOUSE="$(CFLAGSTOUSE)")

