/*
Contiguous Subarrays
You are given an array arr of N integers. For each index i, you are required to determine the number of contiguous subarrays that fulfill the following conditions:

    The value at index i must be the maximum element in the contiguous subarrays, and
    These contiguous subarrays must either start from or end on index i.

Signature
int[] countSubarrays(int[] arr)
Input

    Array arr is a non-empty list of unique integers that range between 1 to 1,000,000,000
    Size N is between 1 and 1,000,000

Output
An array where each index i contains an integer denoting the maximum number of contiguous subarrays of arr[i]
Example:
arr = [3, 4, 1, 6, 2]
output = [1, 3, 1, 5, 1]
Explanation:

    For index 0 - [3] is the only contiguous subarray that starts (or ends) at index 0 with the maximum value in the subarray being 3.
    For index 1 - [4], [3, 4], [4, 1]
    For index 2 - [1]
    For index 3 - [6], [6, 2], [1, 6], [4, 1, 6], [3, 4, 1, 6]
    For index 4 - [2]

So, the answer for the above input is [1, 3, 1, 5, 1]


*/
#include <bits/stdc++.h>
#include "interface_C.h"

// Add any extra import statements you may need here

using namespace std;

//static void check(vector <int>& expected, vector <int>& output);
//static void printIntegerVector(vector <int> array);

// Add any helper functions you may need here
int countMaxLeft(vector<int>& v, int i) {
  int count = 0;
  int val = v[i];
  if(i != 0) {
    for( ; i > 0; i--) {
      if(val > v[i - 1]) {
        count++;
      } else {
        break;
      }
    }
  }
  return count;
}

int countMaxRight(vector<int>& v, int i) {
  int count = 0;
  int val = v[i];
  if(i != v.size() - 1) {
    for( ; i < v.size() - 1; i++) {
      if(val > v[i + 1]) {
        count++;
      } else {
        break;
      }
    }
  }
  return count;
}

vector <int> CountSubarrays(vector <int> arr) {
  // Write your code here
  vector<int> ans;
  ans.resize(arr.size(), 1);
  for(int i = 0; i < arr.size(); i++) {
    ans[i] += countMaxLeft(arr, i);
    ans[i] += countMaxRight(arr, i);
  }
  return ans;
}



// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
static void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

static int test_case_number = 1;

static bool check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size();
  int output_size = output.size();
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = (const char*)u8"\u2713";
  const char* wrongTick = (const char*)u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected);
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl;
  }
  test_case_number++;
  return result;
}

int main_arr_contig_subarrays() {

  int passed = 0;
  vector <int> test_1{3, 4, 1, 6, 2};
  vector <int> expected_1{1, 3, 1, 5, 1};
  vector <int> output_1 = CountSubarrays(test_1);
  bool ans = check(expected_1, output_1);
  if(ans) {
    passed++;
  }

  vector <int> test_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{1, 2, 6, 1, 3, 1};
  vector <int> output_2 = CountSubarrays(test_2);
  ans = check(expected_2, output_2);
  if(ans) {
    passed++;
  }

  // Add your own test cases here

  return passed;
}
