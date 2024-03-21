/*
Seating Arrangements
There are n guests attending a dinner party, numbered from 1 to n. The ith guest
has a height of arr[i-1] inches. The guests will sit down at a circular table
which has n seats, numbered from 1 to n in clockwise order around the table. As
the host, you will choose how to arrange the guests, one per seat. Note that
there are n! possible permutations of seat assignments. Once the guests have sat
down, the awkwardness between a pair of guests sitting in adjacent seats is
defined as the absolute difference between their two heights. Note that, because
the table is circular, seats 1 and n are considered to be adjacent to one
another, and that there are therefore n pairs of adjacent guests. The overall
awkwardness of the seating arrangement is then defined as the maximum
awkwardness of any pair of adjacent guests. Determine the minimum possible
overall awkwardness of any seating arrangement. Signature int
minOverallAwkwardness(int[] arr) Input n is in the range [3, 1000]. Each height
arr[i] is in the range [1, 1000]. Output Return the minimum achievable overall
awkwardness of any seating arrangement. Example n = 4 arr = [5, 10, 6, 8] output
= 4 If the guests sit down in the permutation [3, 1, 4, 2] in clockwise order
around the table (having heights [6, 5, 8, 10], in that order), then the four
awkwardnesses between pairs of adjacent guests will be |6-5| = 1, |5-8| = 3,
|8-10| = 2, and |10-6| = 4, yielding an overall awkwardness of 4. It's
impossible to achieve a smaller overall awkwardness.

*/

#include <bits/stdc++.h>
#include "interface_C.h"
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

int findMaxAbsoluteDifference(deque<int> &d) {
    int ans = -1;
    for (int i = 0; i < d.size(); i++) {
        int ma = 0;
        if (i == (d.size() - 1)) {
            ma = abs(d[d.size() - 1] - d[0]);
        } else {
            ma = abs(d[i] - d[i + 1]);
        }
        if (ma > ans) {
            ans = ma;
        }
    }
    return ans;
}

int minOverallAwkwardness(vector<int> arr) {
    // Write your code here
    deque<int> d;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2) {
            // odd
            d.push_back(arr[i]);
        } else {
            // even
            d.push_front(arr[i]);
        }
    }
    int ans = findMaxAbsoluteDifference(d);
    return ans;
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
static void printInteger(int n) { cout << "[" << n << "]"; }

static int test_case_number = 1;

static void check(int expected, int output) {
    bool result = (expected == output);
    const char *rightTick = (const char *)u8"\u2713";
    const char *wrongTick = (const char *)u8"\u2717";
    if (result) {
        cout << rightTick << "Test #" << test_case_number << "\n";
    } else {
        cout << wrongTick << "Test #" << test_case_number << ": Expected ";
        printInteger(expected);
        cout << " Your output: ";
        printInteger(output);
        cout << endl;
    }
    test_case_number++;
}

int main_greedy_seating_arrangements() {

    vector<int> arr_1{5, 10, 6, 8};
    int expected_1 = 4;
    int output_1 = minOverallAwkwardness(arr_1);
    check(expected_1, output_1);

    vector<int> arr_2{1, 2, 5, 3, 7};
    int expected_2 = 4;
    int output_2 = minOverallAwkwardness(arr_2);
    check(expected_2, output_2);

    // Add your own test cases here

    return 0;
}
