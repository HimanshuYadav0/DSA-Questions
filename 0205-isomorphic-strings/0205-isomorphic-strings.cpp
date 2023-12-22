#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> sToTMapping;
        unordered_map<char, char> tToSMapping;

        for (int i = 0; i < s.length(); ++i) {
            char charS = s[i];
            char charT = t[i];

            if (sToTMapping.find(charS) != sToTMapping.end() && sToTMapping[charS] != charT) {
                return false;
            }

            if (tToSMapping.find(charT) != tToSMapping.end() && tToSMapping[charT] != charS) {
                return false;
            }

            sToTMapping[charS] = charT;
            tToSMapping[charT] = charS;
        }

        return true;
    }
};
