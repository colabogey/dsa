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
#define USE_STACK 1
#if USE_STACK == 0
vector<pair<string, string>> oc = {{"(", ")"}, {"[", "]"}, {"{", "]"}};

bool evalBalance(string &s, int l, int r) {
    // find s[r] in oc
    // is s[l] == first
    for (auto ocPair : oc) {
        string sOp = ocPair.first;
        string sCl = ocPair.second;
        if (s[r] == sCl[0] && s[l] == sOp[0]) {
            return true;
        }
    }
    return false;
}

bool checkBalance(string &s, int l, int r) {
    if (l > r) {
        return false;
    }
    if (evalBalance(s, l, r)) {
        return true;
    }
    checkBalance(s, l + 1, r - 1);
}

bool isBalanced(string s) {
    // Write your code here
    /* seemingly simpler, but does not use a stack */
    bool ans = false;
    ans = checkBalance(s, 0, s.length() - 1);
    return ans;
}

#else
/*  another way using a stack - which may be what is desired by the questiona*/

vector<pair<std::string, std::string>> oc = {
    {"(", ")"}, {"[", "]"}, {"{", "}"}};

bool isCloseBracket(string &s) {
    for (auto ocPair : oc) {
        std::string sOp = ocPair.first;
        std::string sCl = ocPair.second;
        if (s == sCl) {
            return true;
        }
    }
    return false;
}
bool isMatchingBrace(std::string &x, std::string &top) {
    for (auto ocPair : oc) {
        std::string sOp = ocPair.first;
        std::string sCl = ocPair.second;
        if (x == sCl && top == sOp) {
            return true;
        }
    }
    return false;
}

bool isBalanced(string s) {
    // Write your code here
    bool ans = true;
    std::stack<string> brackets;
    for (int i = 0; i < s.length(); i++) {
        std::string x = s.substr(i, 1);
        if (isCloseBracket(x)) {
            bool m = isMatchingBrace(x, brackets.top());
            if (m) {
                brackets.pop();
            } else {
                return false;
            }
        } else {
            brackets.push(x);
        }
        if (brackets.size() == 0) {
            return true;
        }
    }
    return ans;
}

#endif

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

    string s_1 = "{[(])}";
    bool expected_1 = false;
    bool output_1 = isBalanced(s_1);
    check(expected_1, output_1);

    string s_2 = "{{[[(())]]}}";
    bool expected_2 = true;
    bool output_2 = isBalanced(s_2);
    check(expected_2, output_2);

    // Add your own test cases here

    return failed;
}
