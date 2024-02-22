#include <string>
#include <unordered_map>

using namespace std;

void getAllPairs(string s, int l, int r, unordered_map<string, int> res) {
    // Base case
    if (l == r) {
        res[s] = l;
    } else {
        // Permutations made
        for (int i = l; i <= r; i++) {

            // Swapping done
            swap(s[l], s[i]);

            // Recursion called
            getAllPairs(s, l + 1, r, res);

            // backtrack
            swap(s[l], s[i]);
        }
    }
}

int matchingPairs(string s, string t) {
    // Write your code here
    int matches = 0;
    int i = 0;
    unordered_map<string, int> sSet;
    unordered_map<string, int> tSet;
    getAllPairs(s, 0, s.length() - 1, sSet);
    getAllPairs(t, 0, t.length() - 1, tSet);
    for (auto sInSet : sSet) {
        auto res = tSet.find(sInSet.first);
        if (res != tSet.end()) {
            matches++;
        }
    }
    return matches;
}
