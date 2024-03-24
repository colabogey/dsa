/*
Balanced Split
Given an array of integers (which may include repeated integers), determine if
there's a way to split the array into two subsequences A and B such that the sum
of the integers in both arrays is the same, and all of the integers in A are
strictly smaller than all of the integers in B. Note: Strictly smaller denotes
that every integer in A must be less than, and not equal to, every integer in B.
Signature
bool balancedSplitExists(int[] arr)
Input
All integers in array are in the range [0, 1,000,000,000].
Output
Return true if such a split is possible, and false otherwise.
Example 1
arr = [1, 5, 7, 1]
output = true
We can split the array into A = [1, 1, 5] and B = [7].
Example 2
arr = [12, 7, 6, 7, 6]
output = false
We can't split the array into A = [6, 6, 7] and B = [7, 12] since this doesn't
satisfy the requirement that all integers in A are smaller than all integers in
B.
*/
#include <bits/stdc++.h>
#include <numeric>
#include "interface_C.h"
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
int reduce(vector<int> v, int r) {
    int sum = 0;
    for (int i = 0; i < r; i++) {
        sum += v[i];
    }
    return sum;
}

bool balancedSplitExists(vector<int> &arr) {
    // Write your code here
    bool ans = false;
    sort(arr.begin(), arr.end());
    int redge = arr.size() - 1;
    int lsum = reduce(arr, arr.size());
    int rsum = 0;
    int maxElem = 0;
    int i = 0;
    while(true) {
        for(i = redge; i >=0; i--) {
            if(arr[i] >= maxElem) {
                maxElem = arr[i];
                rsum += maxElem;
                lsum -= maxElem;
            } else {
                break;
            }
        }

        if(lsum == rsum) {
            ans = true;
            break;
        } else if(lsum < rsum) {
            ans = false;
            break;
        }
    }

    return ans;
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

static void printString(string &str) { cout << "[\"" << str << "\"]"; }

static int test_case_number = 1;
static int failed = 0;

static void check(bool expected, bool output) {
    bool result = (expected == output);
    const char *rightTick = (const char *)u8"\u2713";
    const char *wrongTick = (const char *)u8"\u2717";
    if (result) {
        cout << rightTick << "Test #" << test_case_number << "\n";
    } else {
        failed++;
        cout << wrongTick << "Test #" << test_case_number << ": Expected ";
        printf("%s", expected ? "true" : "false");
        cout << " Your output: ";
        printf("%s", output ? "true" : "false");
        cout << endl;
    }
    test_case_number++;
}

int main_sort_balanced_split() {
    // Testcase 1
    vector<int> arr_1{2, 1, 2, 5};
    bool expected_1 = true;
    bool output_1 = balancedSplitExists(arr_1);
    check(expected_1, output_1);

    // Testcase 2
    vector<int> arr_2{3, 6, 3, 4, 4};
    bool expected_2 = false;
    bool output_2 = balancedSplitExists(arr_2);
    check(expected_2, output_2);

    // Add your own test cases here

    return failed;
}
