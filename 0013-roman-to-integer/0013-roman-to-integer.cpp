class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_values = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int result = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // If the current numeral is smaller than the next numeral, subtract it.
            if (i + 1 < s.length() && roman_values[s[i]] < roman_values[s[i + 1]]) {
                result -= roman_values[s[i]];
            } else {
                result += roman_values[s[i]];
            }
        }
        
        return result;
    }
};
