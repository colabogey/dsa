
#include "various.h"

int Various::fib_it(int n) {
    if (n == 0) {
        return 0;
    }
    int x = 0;
    int y = 1;
    int z = 0;
    for (int i = 2; i <= n; i++) {
        z = x + y;
        x = y;
        y = z;
    }
    return z;
}
