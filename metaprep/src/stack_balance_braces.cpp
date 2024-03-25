/*
Balance Brackets
A bracket is any of the following characters: (, ), {, }, [, or ].
We consider two brackets to be matching if the first bracket is an open-bracket,
e.g., (, {, or [, and the second bracket is a close-bracket of the same type.
That means ( and ), [ and ], and { and } are the only pairs of matching
brackets. Furthermore, a sequence of brackets is said to be balanced if the
following conditions are met:

    The sequence is empty, or
    The sequence is composed of two or more non-empty sequences, all of which
are balanced, or The first and last brackets of the sequence are matching, and
the portion of the sequence without the first and last elements is balanced.

You are given a string of brackets. Your task is to determine whether each
sequence of brackets is balanced. If a string is balanced, return true,
otherwise, return false Signature bool isBalanced(String s) Input String s with
length between 1 and 1000 Output A boolean representing if the string is
balanced or not Example 1 s = {[()]} output: true Example 2 s = {}() output:
true Example 3 s = {(}) output: false Example 4 s = ) output: false

*/
#include <bits/stdc++.h>
#include "interface_C.h"
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
map<char, char> oc = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
// simpler but no stack
//
bool isBalanced(string s) {
    // Write your code here
    /* seemingly simpler, but does not use a stack */
    int len = s.length();
    int eo = len % 2;
    if(eo == 1) {
        return false;
    }
    for(int r = (len -1), l = 0; r > l; l++, r--) {
        auto found = oc.find(s[l]);
        if(found == oc.end()) {
            return false;
        }
        if(found->second != s[r]) {
            return false;
        }
    }
    return true;
}

// using a stack - which maybe was the objective
//
bool isBalancedStack(string s) {
    stack<char> ob;
    int i = 0;
    for( ; i < s.length(); i++) {
        auto found = oc.find(s[i]);
        if(found == oc.end()) {
            break;
        }
        ob.push(s[i]);
    }

    for( ; i < s.length(); i++) {
        char lastOp = ob.top();
        auto found = oc.find(lastOp);
        if(found->second != s[i]) {
            return false;;
        }
        ob.pop();
    }
    return true;
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

int main_stack_balance_braces() {

    string s_0 = "{[]}";
    bool expected_0 = true;
    bool output_0 = isBalanced(s_0);
    check(expected_0, output_0);

    string s_0s = "{[]}";
    bool expected_0s = true;
    bool output_0s = isBalancedStack(s_0s);
    check(expected_0s, output_0s);

    string s_1 = "{[(])}";
    bool expected_1 = false;
    bool output_1 = isBalanced(s_1);
    check(expected_1, output_1);

    string s_1s = "{[(])}";
    bool expected_1s = false;
    bool output_1s = isBalanced(s_1s);
    check(expected_1s, output_1s);

    string s_2 = "{{[[(())]]}}";
    bool expected_2 = true;
    bool output_2 = isBalanced(s_2);
    check(expected_2, output_2);

    string s_2s = "{{[[(())]]}}";
    bool expected_2s = true;
    bool output_2s = isBalanced(s_2s);
    check(expected_2s, output_2s);

    // Add your own test cases here

    return failed;
}
