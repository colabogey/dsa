# Various structures and algorithms of interest
  - Structured such that each directory is for a particular data structure and various associated algorithms
  - Each item of interest has a test directory and this is the mechanism to exercise the code
  - There is a KDevelop project to use for debugging
*********
- array_shift
  - shifting/rotating array values by various means
- list
  - linked list
  - listC
    - linked list in C. Just wanted to make sure I could use gtest for unit testing C code. 
- hash
  - hash table
- tree
  - binary search tree
    - inorder/preorder/postorder
    - level order
    - rebalance
    - depth
    - add, remove, delete tree 
- graph
  - all tests address shortest path
    - Dijkstra
    - priority queue
    - bfs for unweighted

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
## Code Coverage
- make clean;make debug from src
- make clean;make debug from test
- make tests
- make coverage
- coverage info lives at test/coverage_out/index.html
