#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int countCharacters(std::vector<std::string>& words, std::string chars) {
        int result = 0;
        
        std::unordered_map<char, int> charCount;
        for (char c : chars) {
            charCount[c]++;
        }
        
        for (const std::string& word : words) {
            std::unordered_map<char, int> wordCount;
            bool validWord = true;

            for (char c : word) {
                wordCount[c]++;
            }

            for (const auto& entry : wordCount) {
                if (charCount[entry.first] < entry.second) {
                    validWord = false;
                    break;
                }
            }

            if (validWord) {
                result += word.length();
            }
        }
        
        return result;
    }
};
