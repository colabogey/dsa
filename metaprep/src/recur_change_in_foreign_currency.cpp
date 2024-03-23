/*
Change in a Foreign Currency
You likely know that different currencies have coins and bills of different
denominations. In some currencies, it's actually impossible to receive change
for a given amount of money. For example, Canada has given up the 1-cent penny.
If you're owed 94 cents in Canada, a shopkeeper will graciously supply you with
95 cents instead since there exists a 5-cent coin. Given a list of the available
denominations, determine if it's possible to receive exact change for an amount
of money targetMoney. Both the denominations and target amount will be given in
generic units of that currency. Signature boolean canGetExactChange(int
targetMoney, int[] denominations) Input 1 ≤ |denominations| ≤ 100 1 ≤
denominations[i] ≤ 10,000 1 ≤ targetMoney ≤ 1,000,000 Output Return true if it's
possible to receive exactly targetMoney given the available denominations, and
false if not. Example 1 denominations = [5, 10, 25, 100, 200] targetMoney = 94
output = false
Every denomination is a multiple of 5, so you can't receive exactly 94 units of
money in this currency. Example 2 denominations = [4, 17, 29] targetMoney = 75
output = true
You can make 75 units with the denominations [17, 29, 29].

*/

#include <bits/stdc++.h>
#include "interface_C.h"
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

int getBiggestNumberLessThan(vector<int> &v, int val) {
    int ans = -1;
    vector<int>::reverse_iterator rit;
    for (rit = v.rbegin(); rit != v.rend(); rit++) {
        int x = *rit;
        if (x < val) {
            return x;
        }
    }
    return ans;
}

bool isInDenominations(int val, vector<int> &v) {
    vector<int>::iterator it = find(v.begin(), v.end(), val);
    return (it == v.end() ? false : true);
}

bool canGetExactChange(int targetMoney, vector<int> &denominations) {
    // Write your code here
    sort(denominations.begin(), denominations.end());
    int val = -1;
    while (true) {
        val = getBiggestNumberLessThan(denominations, targetMoney);
        if (val == -1) {
            return false;
        }

        targetMoney -= val;

        if (targetMoney < 0) {
            return false;
        }

        bool found = isInDenominations(targetMoney, denominations);
        if (found) {
            return true;
        }
    }
    return false;
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

int main_recur_change_in_foreign_currency() {
    // Testcase 1
    int target_1 = 94;
    vector<int> arr_1{5, 10, 25, 100, 200};
    bool expected_1 = false;
    bool output_1 = canGetExactChange(target_1, arr_1);
    check(expected_1, output_1);

    // Testcase 2
    int target_2 = 75;
    vector<int> arr_2{4, 17, 29};
    bool expected_2 = true;
    bool output_2 = canGetExactChange(target_2, arr_2);
    check(expected_2, output_2);

    // Add your own test cases here

    return failed;
}
