/*
Minimizing Permutations
In this problem, you are given an integer N, and a permutation, P of the integers from 1 to N, 
    denoted as (a_1, a_2, ..., a_N). 
You want to rearrange the elements of the permutation into increasing order, repeatedly making the following operation:
    Select a sub-portion of the permutation, (a_i, ..., a_j), and reverse its order.
    Your goal is to compute the minimum number of such operations required to return the permutation to increasing order.

Signature
int minOperations(int[] arr)

Input
Array arr is a permutation of all integers from 1 to N, N is between 1 and 8

Output
An integer denoting the minimum number of operations required to arrange the permutation in increasing order

Example
If N = 3, and P = (3, 1, 2), we can do the following operations:

    Select (1, 2) and reverse it: P = (3, 2, 1).
    Select (3, 2, 1) and reverse it: P = (1, 2, 3).

output = 2

*/
#include <bits/stdc++.h>
#include "interface_C.h"
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

// return index of 'out of place' item
// if the next element is less than current, 
//      then current is a transition edge
// -1 if none out of place
//
int findLeftTransition(vector<int>& v, int idx) {
    int i = idx;
    for( ; i < (v.size() - 1); i++) {
        if(v[i + 1] < v[i]) {
            return i;
        }
    }
    return -1;
}

// return index of 'out of place' item
// -1 if none out of place
// starting at the 'left edge element' if the next is increasing
//      this current is the right edge
//
int findRightTransition(vector<int>& v, int idx) {
    int i = idx;
    for( ; i < (v.size() - 1); i++) {
        if(v[i + 1] > v[i]) {
            return i;
        }
    }
    return -1;
}

void rotate(vector<int>& v, int leftIdx, int rightIdx) {
    vector<int> tmp;
    int range = (rightIdx - leftIdx) + 1;   // zero based
    tmp.resize(range);
    for(int i = 0, idx = leftIdx; i < range; i++, idx++) {
        tmp[i] = v[idx];
    }

    for(int i = 0, idx = leftIdx; i < range; i++, idx++) {
        int item = tmp.back();
        tmp.pop_back();
        v[idx] = item;
    }
}

int minOperations(vector <int> arr) {
  // Write your code here
  /*
  find transition to lesser item - that's the left
  from there find transition to greater value - that's the right
  rotate from left end to right end
  
  */
  int leftIdx = 0;
  int rightIdx = 0;
  int rotations = 0;
  while(true) {
    leftIdx = findLeftTransition(arr, leftIdx);
    if(leftIdx == -1) {
        break;
    }
    rightIdx = findRightTransition(arr, leftIdx);
    if(rightIdx == -1) {
        rightIdx = arr.size() - 1;
    }
    rotate(arr, leftIdx, rightIdx);
    rotations++;
    leftIdx = 0;
  }

  return rotations;
}




// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printInteger(int n) {
  cout << "[" << n << "]";
}

static int test_case_number = 1;
static int failed = 0;

void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = (const char*)u8"\u2713";
  const char* wrongTick = (const char*)u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    failed++;
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected); 
    cout << " Your output: ";
    printInteger(output);
    cout << endl; 
  }
  test_case_number++;
}

int main_minOperations() {

  int n_1 = 5;
  vector <int> arr_1{1, 2, 5, 4, 3};
  int expected_1 = 1;
  int output_1 = minOperations(arr_1);
  check(expected_1, output_1);

  int n_2 = 3;
  vector <int> arr_2{3, 1, 2};
  int expected_2 = 2;
  int output_2 = minOperations(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
  return failed;
}
