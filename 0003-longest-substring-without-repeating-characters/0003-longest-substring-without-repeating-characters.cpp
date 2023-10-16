class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.size();
        int maxLength = 0;
        std::unordered_map<char, int> charIndex;

        for (int i = 0, j = 0; j < n; j++) {
            if (charIndex.find(s[j]) != charIndex.end()) {
   
                i = std::max(i, charIndex[s[j]] + 1);
            }
            charIndex[s[j]] = j;
            maxLength = std::max(maxLength, j - i + 1);
        }

        return maxLength;
    }
};
