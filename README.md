# array_shift
- just messing around with shifting array values

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
- cd array_shift
- make
  - there are several make targets, but this will build the release version. And that's fine to start with.
## Run
- cd array_shift/test
- make
- run the test executable in the bin directory
