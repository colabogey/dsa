
#pragma once

#define QSET 1
#define QGET 2

typedef struct _q {
    int op;
    int idx;
} query;
