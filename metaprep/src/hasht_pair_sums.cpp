/*
Pair Sums
Given a list of n integers arr[0..(n-1)], determine the number of different pairs of elements within it which sum to k.
If an integer appears in the list multiple times, each copy is considered to be different; that is, two pairs are considered different if one pair includes at least one array index which the other doesn't, even if they include the same values.
Signature
int numberOfWays(int[] arr, int k)
Input
n is in the range [1, 100,000].
Each value arr[i] is in the range [1, 1,000,000,000].
k is in the range [1, 1,000,000,000].
Output
Return the number of different pairs of elements which sum to k.
Example 1
n = 5
k = 6
arr = [1, 2, 3, 4, 3]
output = 2
The valid pairs are 2+4 and 3+3.
Example 2
n = 5
k = 6
arr = [1, 5, 3, 3, 3]
output = 4
There's one valid pair 1+5, and three different valid pairs 3+3 (the 3rd and 4th elements, 3rd and 5th elements, and 4th and 5th elements).


*/

#include <bits/stdc++.h>
#include "interface_C.h"
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
map<int, int> elems;
vector<int> noConsider;

bool isNoConsider(int val) {
  auto it = std::find(noConsider.begin(), noConsider.end(), val);
  return (it == noConsider.end()) ? false : true;
}

int fact(int n) {
  if((n == 0) || (n == 1)) {
    return 1;
  }
  return(n * (n -1));
}

int _findPairs(int val, int baseNum) {
  int ans = 0;
  if (auto search = elems.find(val); search != elems.end()) {
    if(isNoConsider(val)) {
      return ans;
    }
    int freq = search->second;
    noConsider.push_back(search->first);
    if(freq == 1) {
      ans = 1;
      // like for 6 zap both 4 and 2
      noConsider.push_back(baseNum - search->first);
    } else {
      // calculate the combinations
      // ans = fact(n) / (fact(r) * fact(n-r));
      // doing pairs so r == 2
      ans = fact(freq) / 2 * fact(freq - 2);
    }
  }
  return ans;
}

int numberOfWays(vector<int>& arr, int k) {
  // Write your code here
  elems.clear();
  noConsider.clear();
  int ans = 0;
  for(int i = 0; i < arr.size(); i++) {
    elems[arr[i]]++;
  }
  for(int i = 0; i < arr.size(); i++) {
    int n = _findPairs(k - arr[i], k);
    if(n != -1) {
      ans += n;
    }
  }
  return ans;
}





// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

static void printInteger(int n) {
  cout << "[" << n << "]";
}

static int test_case_number = 1;

static void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = (const char*)u8"\u2713";
  const char* wrongTick = (const char*)u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected);
    cout << " Your output: ";
    printInteger(output);
    cout << endl;
  }
  test_case_number++;
}

int main_hasht_pair_sums() {

  int k_1 = 6;
  vector <int> arr_1{1, 2, 3, 4, 3};
  int expected_1 = 2;
  int output_1 = numberOfWays(arr_1, k_1);
  check(expected_1, output_1);

  int k_2 = 6;
  vector <int> arr_2{1, 5, 3, 3, 3};
  int expected_2 = 4;
  int output_2 = numberOfWays(arr_2, k_2);
  check(expected_2, output_2);

  // Add your own test cases here

  return 0;
}
