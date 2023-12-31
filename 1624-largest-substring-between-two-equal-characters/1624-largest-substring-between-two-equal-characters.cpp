
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> firstOccurrence;
        int maxLength = -1;

        for (int i = 0; i < s.length(); ++i) {
            char currentChar = s[i];
            if (firstOccurrence.find(currentChar) == firstOccurrence.end()) {
                firstOccurrence[currentChar] = i;
            } else {
                maxLength = max(maxLength, i - firstOccurrence[currentChar] - 1);
            }
        }

        return maxLength;
    }
};
