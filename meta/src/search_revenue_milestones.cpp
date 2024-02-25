/*
Revenue Milestones
We keep track of the revenue Facebook makes every day, and we want to know on what days Facebook hits certain revenue milestones. Given an array of the revenue on each day, and an array of milestones Facebook wants to reach, return an array containing the days on which Facebook reached every milestone.
Signature
int[] getMilestoneDays(int[] revenues, int[] milestones)
Input
revenues is a length-N array representing how much revenue FB made on each day (from day 1 to day N). milestones is a length-K array of total revenue milestones.
Output
Return a length-K array where K_i is the day on which FB first had milestones[i] total revenue. If the milestone is never met, return -1.
Example
revenues = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
milestones = [100, 200, 500]
output = [4, 6, 10]
Explanation
On days 4, 5, and 6, FB has total revenue of $100, $150, and $210 respectively. Day 6 is the first time that FB has >= $200 of total revenue.


*/
#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

vector<int> findMileStone_orig(vector<int>& c, int m, vector<int>& ans) {
  for(int i = 0; i < c.size(); i++) {
    if(c[i] >= m) {
      ans.push_back(i + 1);
      break;
    }
  }
  return ans;
}

vector<int> findMileStone(vector<int>& c, int m, vector<int>& ans) {
  int l = 0;
  int r = c.size() -1;
  while(r >= l) {
    int mid = (l + r)/2;
    if(c[mid] == m) {
      // lucky
      ans.push_back(mid + 1);
      break;
    } else if(c[mid] >= m) {
      //make sure left is smaller - could be two in a row
      if(mid == 0) {
        // this is the first one greater
        ans.push_back(mid + 1);
        break;
      } else if(c[mid - 1] >= m) {
        // answer is on the left side
        r = (mid - 1);
        continue;
      } else {
        // first one greater
        ans.push_back(mid + 1);
        break;
      }
    } else {
      // c[mid] < m, answer lies to the right
      l = mid + 1;
      continue;
    }
  }
  return ans;
}

vector <int> getMilestoneDays(vector <int> revenues, vector<int> milestones) {
  // Write your code here
  vector<int>ans;
  vector<int> cumValues(revenues.size(), 0);
  cumValues[0] = revenues[0];
  for(int i = 1; i < cumValues.size() ; i++) {
    cumValues[i] = cumValues[i - 1] + revenues[i];
  }
  for(int i : milestones) {
    findMileStone(cumValues, i, ans);
  }
  return ans;
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
  // Testcase 1
  int n_1 = 5, k_1 = 4;
  vector <int> revenues_1{100, 200, 300, 400, 500};
  vector <int> milestones_1{300, 800, 1000, 1400};
  vector <int> expected_1{2, 4, 4, 5};
  vector <int> output_1 = getMilestoneDays(revenues_1, milestones_1);
  check(expected_1, output_1);

  // Testcase 2
  int n_2 = 6, k_2 = 5;
  vector <int> revenues_2{700, 800, 600, 400, 600, 700};
  vector <int> milestones_2{3100, 2200, 800, 2100, 1000};
  vector <int> expected_2{5, 4, 2, 3, 2};
  vector <int> output_2 = getMilestoneDays(revenues_2, milestones_2);
  check(expected_2, output_2);

  // Add your own test cases here

}
