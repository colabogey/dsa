#include "anagram.h"
#include <algorithm>
#include <unordered_map>

bool Anagram::isAnagramSort(std::string &a, std::string &b) {
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    return (a == b);
}

bool Anagram::isAnagramUnorderedMap(std::string &a, std::string &b) {
    bool ans = true;
    std::unordered_map<char, int> us;

    for (int i = 0; i < a.length(); i++) {
        us[a[i]]++;
    }

    for (auto c : b) {
        auto found = us.find(c);
        if (found == us.end()) {
            ans = false;
            break;
        } else if (found->second > 1) {
            found->second--;
        } else if (found->second <= 0) {
            ans = false;
            break;
        }
    }
    return ans;
}
