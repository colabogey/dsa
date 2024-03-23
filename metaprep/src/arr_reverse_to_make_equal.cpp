/*

Reverse to Make Equal
Given two arrays A and B of length N, determine if there is a way to make A
equal to B by reversing any subarrays from array B any number of times.
Signature
bool areTheyEqual(int[] arr_a, int[] arr_b)
Input
All integers in array are in the range [0, 1,000,000,000].
Output
Return true if B can be made equal to A, return false otherwise.
Example
A = [1, 2, 3, 4]
B = [1, 4, 3, 2]
output = true
After reversing the subarray of B from indices 1 to 3, array B will equal array
A.


*/
#include <bits/stdc++.h>
#include "interface_C.h"
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

bool areTheyEqual(vector<int> &array_a, vector<int> &array_b) {
    // Write your code here
    sort(array_a.begin(), array_a.end());
    sort(array_b.begin(), array_b.end());
    bool eq = true;
    for (int i = 0; i < array_a.size(); i++) {
        if (array_a[i] != array_b[i]) {
            eq = false;
            break;
        }
    }
    return eq;
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

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

int main_arr_reverse_to_make_equal() {
    vector<int> array_a_1{1, 2, 3, 4};
    vector<int> array_b_1{1, 4, 3, 2};
    bool expected_1 = true;
    bool output_1 = areTheyEqual(array_a_1, array_b_1);
    check(expected_1, output_1);

    vector<int> array_a_2{1, 2, 3, 4};
    vector<int> array_b_2{1, 4, 3, 3};
    bool expected_2 = false;
    bool output_2 = areTheyEqual(array_a_2, array_b_2);
    check(expected_2, output_2);

    // Add your own test cases here

    return failed;
}
