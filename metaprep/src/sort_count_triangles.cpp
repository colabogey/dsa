/*
Counting Triangles
Given a list of N triangles with integer side lengths, determine how many
different triangles there are. Two triangles are considered to be the same if
they can both be placed on the plane such that their vertices occupy exactly the
same three points. Signature int countDistinctTriangles(ArrayList<Sides> arr) or
int countDistinctTrianges(int[][] arr)
Input
In some languages, arr is an Nx3 array where arr[i] is a length-3 array that
contains the side lengths of the ith triangle. In other languages, arr is a list
of structs/objects that each represent a single triangle with side lengths a, b,
and c. It's guaranteed that all triplets of side lengths represent real
triangles. All side lengths are in the range [1, 1,000,000,000] 1 <= N <=
1,000,000 Output Return the number of distinct triangles in the list. Example 1
arr = [[2, 2, 3], [3, 2, 2], [2, 5, 6]]
output = 2
The first two triangles are the same, so there are only 2 distinct triangles.
Example 2
arr = [[8, 4, 6], [100, 101, 102], [84, 93, 173]]
output = 3
All of these triangles are distinct.
Example 3
arr = [[5, 8, 9], [5, 9, 8], [9, 5, 8], [9, 8, 5], [8, 9, 5], [8, 5, 9]]
output = 1
All of these triangles are the same.

*/
#include <bits/stdc++.h>
#include "interface_C.h"
// Add any extra import statements you may need here

using namespace std;

struct sides {
    long long a;
    long long b;
    long long c;
};

// Add any helper functions you may need here

int makeSideKey(sides s) {
    int sideKey = -1;
    vector<int> v;
    v.push_back(s.a);
    v.push_back(s.b);
    v.push_back(s.c);
    sort(v.begin(), v.end());
    sideKey = (v[0] + v[1]) * v[2];
    return sideKey;
}
void addSide(map<int, int> &m, sides s) {
    int sideKey = makeSideKey(s);
    m[sideKey]++;
}

int countDistinctTriangles(vector<sides> arr) {
    // Write your code here
    map<int, int> distinct;
    for (auto s : arr) {
        addSide(distinct, s);
    }
    return distinct.size();
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

int main_sort_count_triangles() {

    vector<sides> arr_1 = {
        {7, 6, 5}, {5, 7, 6}, {8, 2, 9}, {2, 3, 4}, {2, 4, 3}};
    int expected_1 = 3;
    int output_1 = countDistinctTriangles(arr_1);
    check(expected_1, output_1);

    vector<sides> arr_2 = {{3, 4, 5}, {8, 8, 9}, {7, 7, 7}};
    int expected_2 = 3;
    int output_2 = countDistinctTriangles(arr_2);
    check(expected_2, output_2);

    // Add your own test cases here

    return failed;
}
