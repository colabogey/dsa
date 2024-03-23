/*
Magical Candy Bags
You have N bags of candy. The ith bag contains arr[i] pieces of candy, and each
of the bags is magical! It takes you 1 minute to eat all of the pieces of candy
in a bag (irrespective of how many pieces of candy are inside), and as soon as
you finish, the bag mysteriously refills. If there were x pieces of candy in the
bag at the beginning of the minute, then after you've finished you'll find that
floor(x/2) pieces are now inside. You have k minutes to eat as much candy as
possible. How many pieces of candy can you eat? Signature int maxCandies(int[]
arr, int K) Input 1 ≤ N ≤ 10,000 1 ≤ k ≤ 10,000 1 ≤ arr[i] ≤ 1,000,000,000
Output
A single integer, the maximum number of candies you can eat in k minutes.
Example 1
N = 5
k = 3
arr = [2, 1, 7, 4, 2]
output = 14
In the first minute you can eat 7 pieces of candy. That bag will refill with
floor(7/2) = 3 pieces. In the second minute you can eat 4 pieces of candy from
another bag. That bag will refill with floor(4/2) = 2 pieces. In the third
minute you can eat the 3 pieces of candy that have appeared in the first bag
that you ate. In total you can eat 7 + 4 + 3 = 14 pieces of candy.


*/
#include <bits/stdc++.h>
#include "interface_C.h"
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

int maxCandies(vector<int> arr, int k) {
    // Write your code here

    return 0;
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
static void printInteger(int n) { cout << "[" << n << "]"; }

static int test_case_number = 1;
static int failed = 0;

static void check(int expected, int output) {
    bool result = (expected == output);
    const char *rightTick = (const char *)u8"\u2713";
    const char *wrongTick = (const char *)u8"\u2717";
    if (result) {
        cout << rightTick << "Test #" << test_case_number << "\n";
    } else {
        failed++;
        cout << wrongTick << "Test #" << test_case_number << ": Expected ";
        printInteger(expected);
        cout << " Your output: ";
        printInteger(output);
        cout << endl;
    }
    test_case_number++;
}

int main_heap_magical_bags() {

    int k_1 = 3;
    vector<int> arr_1{2, 1, 7, 4, 2};
    int expected_1 = 14;
    int output_1 = maxCandies(arr_1, k_1);
    check(expected_1, output_1);

    int k_2 = 3;
    vector<int> arr_2{19, 78, 76, 72, 48, 8, 24, 74, 29};
    int expected_2 = 228;
    int output_2 = maxCandies(arr_2, k_2);
    check(expected_2, output_2);

    // Add your own test cases here

    return failed;
}
