/*
Encrypted Words
You've devised a simple encryption method for alphabetic strings that shuffles
the characters in such a way that the resulting string is hard to quickly read,
but is easy to convert back into the original string. When you encrypt a string
S, you start with an initially-empty resulting string R and append characters to
it as follows:

    Append the middle character of S (if S has even length, then we define the
middle character as the left-most of the two central characters) Append the
encrypted version of the substring of S that's to the left of the middle
character (if non-empty) Append the encrypted version of the substring of S
that's to the right of the middle character (if non-empty)

For example, to encrypt the string "abc", we first take "b", and then append the
encrypted version of "a" (which is just "a") and the encrypted version of "c"
(which is just "c") to get "bac". If we encrypt "abcxcba" we'll get "xbacbca".
That is, we take "x" and then append the encrypted version "abc" and then append
the encrypted version of "cba". Input S contains only lower-case alphabetic
characters 1 <= |S| <= 10,000 Output Return string R, the encrypted version of
S. Example 1 S = "abc" R = "bac" Example 2 S = "abcd" R = "bacd" Example 3 S =
"abcxcba" R = "xbacbca" Example 4 S = "facebook" R = "eafcobok"

*/
#include <bits/stdc++.h>
#include "interface_C.h"
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

string findEncryptedWord(string s) {
    // Write your code here
    if (s.length() <= 1)
        return s;

    int mid = (s.length() - 1) / 2;

    return s[mid] + findEncryptedWord(s.substr(0, mid)) +
           findEncryptedWord(s.substr(mid + 1, s.length()));
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

static void printString(string &str) { cout << "[\"" << str << "\"]"; }

static int test_case_number = 1;
static int failed = 0;

static void check(string &expected, string &output) {
    bool result = (expected == output);
    const char *rightTick = (const char *)u8"\u2713";
    const char *wrongTick = (const char *)u8"\u2717";
    if (result) {
        cout << rightTick << " Test #" << test_case_number << "\n";
    } else {
        failed++;
        cout << wrongTick << " Test #" << test_case_number << ": Expected ";
        printString(expected);
        cout << " Your output: ";
        printString(output);
        cout << endl;
    }
    test_case_number++;
}

int main_recur_encrypted_words() {

    string s_1 = "abc";
    string expected_1 = "bac";
    string output_1 = findEncryptedWord(s_1);
    check(expected_1, output_1);

    string s_2 = "abcd";
    string expected_2 = "bacd";
    string output_2 = findEncryptedWord(s_2);
    check(expected_2, output_2);

    // Add your own test cases here

    return failed;
}
