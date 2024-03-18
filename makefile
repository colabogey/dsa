SUBDIRS := array_shift hash list tree graph avltree listC \
	dynamicArray various metaprep

PROJECT_NAME = oracle
ifeq (, $(PROJECTS_BASE))
PROJECT_BASE = ${HOME}/projects/${PROJECT_NAME}
else
PROJECT_BASE = ${PROJECTS_BASE}/${PROJECT_NAME}
endif

include $(PROJECT_BASE)/generic.mk
