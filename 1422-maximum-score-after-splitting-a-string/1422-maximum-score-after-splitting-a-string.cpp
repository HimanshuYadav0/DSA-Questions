#include <string>
#include <algorithm>

class Solution {
public:
    int maxScore(std::string s) {
        int zeros = 0, ones = 0;
        int maxScore = 0;

        // Count the number of ones in the entire string
        for (char c : s) {
            if (c == '1') {
                ones++;
            }
        }

        // Iterate through the string to find the maximum score after splitting
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '0') {
                zeros++;
            } else {
                ones--;
            }

            // Update the maximum score
            maxScore = std::max(maxScore, zeros + ones);
        }

        return maxScore;
    }
};
