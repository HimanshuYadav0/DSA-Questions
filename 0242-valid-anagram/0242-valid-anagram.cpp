#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, int> charCount;

        for (char c : s) {
            charCount[c]++;
        }

        for (char c : t) {
            if (charCount.find(c) == charCount.end() || charCount[c] == 0) {
                return false;
            }
            charCount[c]--;
        }

        for (const auto& entry : charCount) {
            if (entry.second != 0) {
                return false;
            }
        }

        return true;
    }
};
