# Various structures and algorithms of interest
- shifting/rotating array values
- linked list
- hash table
- binary search tree
- mergesort
  - just beginning here. It works (I copied it), but I don't know exactly how yet

# Download, Build, Run
## Download
- Clone the repo
  - I put it in ${HOME}/projects
  - The makefiles navigate like this
```
PROJECT_NAME = waitables
ifeq (, $(PROJECTS_BASE))
PROJECT_BASE = ${HOME}/projects/${PROJECT_NAME}
else
PROJECT_BASE = ${PROJECTS_BASE}/${PROJECT_NAME}
endif
```
  - So presumably you can locate the project base anywhere and set the environment variable PROJECTS_BASE appropriately. I think I tried this once. Maybe just put it in ${HOME}/projects.
## Build
- make from the top initially, just to see if its all setup correctly
- cd to a src directory of interest, e.g., cd tree
- make
  - there are several make targets, but this will build the release version. And that's fine to start with.
  - the makefile produced a library, e.g., libtree.a
## Run
- cd to the test directory, e.g., cd tree/test
- make
- run the test executable in the bin directory to utilize the library items
