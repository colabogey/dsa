/*

Queue Removals
You're given a list of n integers arr, which represent elements in a queue (in
order from front to back). You're also given an integer x, and must perform x
iterations of the following 3-step process:

    Pop x elements from the front of queue (or, if it contains fewer than x
elements, pop all of them) Of the elements that were popped, find the one with
the largest value (if there are multiple such elements, take the one which had
been popped the earliest), and remove it For each one of the remaining elements
that were popped (in the order they had been popped), decrement its value by 1
if it's positive (otherwise, if its value is 0, then it's left unchanged), and
then add it back to the queue

Compute a list of x integers output, the ith of which is the 1-based index in
the original array of the element which had been removed in step 2 during the
ith iteration. Signature int[] findPositions(int[] arr, int x) Input x is in the
range [1, 316]. n is in the range [x, x*x]. Each value arr[i] is in the range
[1, x]. Output Return a list of x integers output, as described above. Example
n = 6
arr = [1, 2, 2, 3, 4, 5]
x = 5
output = [5, 6, 4, 1, 2]
The initial queue is [1, 2, 2, 3, 4, 5] (from front to back).
In the first iteration, the first 5 elements are popped off the queue, leaving
just [5]. Of the popped elements, the largest one is the 4, which was at index 5
in the original array. The remaining elements are then decremented and added
back onto the queue, whose contents are then [5, 0, 1, 1, 2]. In the second
iteration, all 5 elements are popped off the queue. The largest one is the 5,
which was at index 6 in the original array. The remaining elements are then
decremented (aside from the 0) and added back onto the queue, whose contents are
then [0, 0, 0, 1]. In the third iteration, all 4 elements are popped off the
queue. The largest one is the 1, which had the initial value of 3 at index 4 in
the original array. The remaining elements are added back onto the queue, whose
contents are then [0, 0, 0]. In the fourth iteration, all 3 elements are popped
off the queue. Since they all have an equal value, we remove the one that was
popped first, which had the initial value of 1 at index 1 in the original array.
The remaining elements are added back onto the queue, whose contents are then
[0, 0]. In the final iteration, both elements are popped off the queue. We
remove the one that was popped first, which had the initial value of 2 at index
2 in the original array.


*/
#include <bits/stdc++.h>
#include "interface_C.h"
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

vector <int> findPositions(vector <int> arr, int x) {
  // Write your code here
  vector<int> ans;
  queue<pair<int, int>> q;
  queue<pair<int, int>> qPruned;
  for(int i = 0; i < arr.size(); i++) {
    q.push(make_pair(arr[i], (i + 1)));
  }

  for(int i = 0; i < x; i++) {
    // pop  x elements - no more than q.size()
    int popCount = min((int)q.size(), x);
    pair<int, int> maxEntry{-1, 0};
    for(int j = 0; j < popCount; j++) {
        auto p = q.front();
        if(p.first > maxEntry.first) {
            maxEntry = p;
        }
        qPruned.push(p);
        q.pop();
    }
    // save max index - the answer
    ans.push_back(maxEntry.second);

    // put everything except maxEntry back
    while(!qPruned.empty()) {
        auto item = qPruned.front();
        qPruned.pop();
        if(item != maxEntry) {
            if(item.first > 0) {
                item.first--;
            }
            q.push(item);
        }
    }
  }
  return ans;
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
static void printIntegerVector(vector<int> array) {
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
static int failed = 0;

static void check(vector<int> &expected, vector<int> &output) {
    int expected_size = expected.size();
    int output_size = output.size();
    bool result = true;
    if (expected_size != output_size) {
        result = false;
    }
    for (int i = 0; i < min(expected_size, output_size); i++) {
        result &= (output[i] == expected[i]);
    }
    const char *rightTick = (const char *)u8"\u2713";
    const char *wrongTick = (const char *)u8"\u2717";
    if (result) {
        cout << rightTick << " Test #" << test_case_number << "\n";
    } else {
        failed++;
        cout << wrongTick << " Test #" << test_case_number << ": Expected ";
        printIntegerVector(expected);
        cout << " Your output: ";
        printIntegerVector(output);
        cout << endl;
    }
    test_case_number++;
}

int main_queue_removals() {
    int n_1 = 6;
    int x_1 = 5;
    vector<int> arr_1{1, 2, 2, 3, 4, 5};
    vector<int> expected_1{5, 6, 4, 1, 2};
    vector<int> output_1 = findPositions(arr_1, x_1);
    check(expected_1, output_1);

    int n_2 = 13;
    int x_2 = 4;
    vector<int> arr_2{2, 4, 2, 4, 3, 1, 2, 2, 3, 4, 3, 4, 4};
    vector<int> expected_2{2, 5, 10, 13};
    vector<int> output_2 = findPositions(arr_2, x_2);
    check(expected_2, output_2);

    // Add your own test cases here

    return failed;
}
