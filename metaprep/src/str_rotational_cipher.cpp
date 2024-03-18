/*
Rotational Cipher
One simple way to encrypt a string is to "rotate" every alphanumeric character by a certain amount. Rotating a character means replacing it with another character that is a certain number of steps away in normal alphabetic or numerical order.
For example, if the string "Zebra-493?" is rotated 3 places, the resulting string is "Cheud-726?". Every alphabetic character is replaced with the character 3 letters higher (wrapping around from Z to A), and every numeric character replaced with the character 3 digits higher (wrapping around from 9 to 0). Note that the non-alphanumeric characters remain unchanged.
Given a string and a rotation factor, return an encrypted string.
Signature
string rotationalCipher(string input, int rotationFactor)
Input
1 <= |input| <= 1,000,000
0 <= rotationFactor <= 1,000,000
Output
Return the result of rotating input a number of times equal to rotationFactor.
Example 1
input = Zebra-493?
rotationFactor = 3
output = Cheud-726?
Example 2
input = abcdefghijklmNOPQRSTUVWXYZ0123456789
rotationFactor = 39
output = nopqrstuvwxyzABCDEFGHIJKLM9012345678


*/
#include <bits/stdc++.h>
#include "interface_C.h"
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

void setItem(string& input, int rotationFactor, string& baseItems, int inputSpot) {
  int rf = rotationFactor % baseItems.length();
  int spot = baseItems.find(input[inputSpot]);
  int idx = spot + rf;

  if(idx > baseItems.length()) {
    idx = (idx - baseItems.length());
  }
  input[inputSpot] = baseItems[idx];
}

string rotationalCipher(string input, int rotationFactor) {
  // Write your code here
  string lc = "abcdefghijklmnopqrstuvwxyz";
  string uc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string nm = "0123456789";
  string output = input;
  for(int i = 0; i < output.length(); i++) {
    if(isalpha(output[i]) && isupper(input[i])) {
      setItem(output, rotationFactor, uc, i);
    } else if(isalpha(output[i])) {
      setItem(output, rotationFactor, lc, i);
    } else if(isdigit(output[i])) {
      setItem(output, rotationFactor, nm, i);
    } else {
      output[i] = input[i];
    }
  }
  return output;
}


// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

static void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

static int test_case_number = 1;

static void check(string& expected, string& output) {
  bool result = (expected == output);
  const char* rightTick = (const char*)u8"\u2713";
  const char* wrongTick = (const char*)u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printString(expected);
    cout << " Your output: ";
    printString(output);
    cout << endl;
  }
  test_case_number++;
}

int main_str_rotational_cipher() {

  string input_1 = "All-convoYs-9-be:Alert1.";
  int rotationFactor_1 = 4;
  string expected_1 = "Epp-gsrzsCw-3-fi:Epivx5.";
  string output_1 = rotationalCipher(input_1, rotationFactor_1);
  check(expected_1, output_1);

  string input_2 = "abcdZXYzxy-999.@";
  int rotationFactor_2 = 200;
  string expected_2 = "stuvRPQrpq-999.@";
  string output_2 = rotationalCipher(input_2, rotationFactor_2);
  check(expected_2, output_2);

  // Add your own test cases here

  return 0;
}
