
class Solution {
public:
    int minOperations(std::string s) {
        int n = s.length();
        int count1 = 0, count2 = 0;

        // Case 1: Start with '0'
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && s[i] != '0') {
                count1++;
            } else if (i % 2 == 1 && s[i] != '1') {
                count1++;
            }
        }

        // Case 2: Start with '1'
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && s[i] != '1') {
                count2++;
            } else if (i % 2 == 1 && s[i] != '0') {
                count2++;
            }
        }

        // Return the minimum count
        return std::min(count1, count2);
    }
};
