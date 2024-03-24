#include "sum3.h"
#include <cstdio>

/*
like:
3 6 7 8 -2 -28 53 -11 12 47

*/
bool Sum3ToZero::canThreeSumToZero(std::vector<int> &arr) {
    bool ans = false;
    std::unordered_map<int, int> m;
    for (int i = 0; i < arr.size(); i++) {
        m[arr[i]]++;
    }

    for (int i = 0; i < arr.size(); i++) {
        ans = _findTwo(m, arr, i, (i + 1));
        if (ans) {
            break;
        }
    }
    return ans;
}

bool Sum3ToZero::_findTwo(std::unordered_map<int, int> &m,
                          std::vector<int> &arr, int targetIdx, int beginIdx) {
    bool ans = false;
    if (beginIdx >= arr.size()) {
        return false;
    }
    int target = arr[targetIdx];           // like 3
    int targetSum = target - (target * 2); // like -3

    for (int i = beginIdx; i < arr.size() - 1; i++) {
        int addend1 = arr[i]; // like 8
        int lookingFor = (addend1 + target) * -1;
        auto search = m.find(lookingFor);
        if (search != m.end()) {
            ans = true;
            break;
        }
    }
    return ans;
}
