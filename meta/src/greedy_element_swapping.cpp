/*
Element Swapping
Given a sequence of n integers arr, determine the lexicographically smallest sequence which may be obtained from it after performing at most k element swaps, each involving a pair of consecutive elements in the sequence.
Note: A list x is lexicographically smaller than a different equal-length list y if and only if, for the earliest index at which the two lists differ, x's element at that index is smaller than y's element at that index.
Signature
int[] findMinArray(int[] arr, int k)
Input
n is in the range [1, 1000].
Each element of arr is in the range [1, 1,000,000].
k is in the range [1, 1000].
Output
Return an array of n integers output, the lexicographically smallest sequence achievable after at most k swaps.
Example 1
n = 3
k = 2
arr = [5, 3, 1]
output = [1, 5, 3]
We can swap the 2nd and 3rd elements, followed by the 1st and 2nd elements, to end up with the sequence [1, 5, 3]. This is the lexicographically smallest sequence achievable after at most 2 swaps.
Example 2
n = 5
k = 3
arr = [8, 9, 11, 2, 1]
output = [2, 8, 9, 11, 1]
We can swap [11, 2], followed by [9, 2], then [8, 2].

*/

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

int findSmallest(vector<int>& arr, int right) {
  int smallest = INT_MAX;
  int smallestIdx = 0;
  for(int i = 0; i <= right; i++) {
    if(arr[i] < smallest) {
      smallest = arr[i];
      smallestIdx = i;
    }
  }
  return smallestIdx;
}

void swapConsecutive(vector<int>& arr, int smallestIdx) {
  if(smallestIdx == 0) {
    return;
  }

  int save = arr[smallestIdx - 1];
  arr[smallestIdx - 1] = arr[smallestIdx];
  arr[smallestIdx] = save;
}

vector <int> findMinArray(vector <int> arr, int k) {
  // Write your code here
  int right = k;
  for(; k > 0; k--) {
    int idx = findSmallest(arr, right);
    swapConsecutive(arr, idx);
  }
  return arr;
}




// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printIntegerVector(vector <int> array) {
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

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size();
  int output_size = output.size();
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
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
}

int main() {

  int n_1 = 3, k_1 = 2;
  vector <int> arr_1{5, 3, 1};
  vector <int> expected_1{1, 5, 3};
  vector <int> output_1 = findMinArray(arr_1,k_1);
  check(expected_1, output_1);

  int n_2 = 5, k_2 = 3;
  vector <int> arr_2{8, 9 ,11, 2, 1};
  vector <int> expected_2{2, 8, 9, 11, 1};
  vector <int> output_2 = findMinArray(arr_2,k_2);
  check(expected_2, output_2);

  // Add your own test cases here

}
