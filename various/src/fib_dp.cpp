/*
def fibonacci(n):
    # Create an array of size (n+1) to store the computed values
    dp = [0, 1] + [0] * (n - 1)

    for i in range(2, n + 1):
        # Compute the ith Fibonacci number
        dp[i] = dp[i - 1] + dp[i - 2]

    return dp[n]

print(fibonacci(10))  # Outputs: 55
*/

#include "various.h"
#include <deque>

int Various::fib_dp(int n) {
    std::deque<int> fib(n + 1, 0);
    fib[0] = 0;
    fib[1] = 1;
    int i;
    for (i = 2; i < (n + 1); i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]);
    }
    return fib[n];
}
