
class Solution {
public:
    bool makeEqual(std::vector<std::string>& words) {
        std::unordered_map<char, int> charCount;

        // Count the frequency of each character in all strings
        for (const std::string& word : words) {
            for (char c : word) {
                charCount[c]++;
            }
        }

        // Check if the count of each character is divisible by the total number of strings
        int totalStrings = words.size();
        for (const auto& entry : charCount) {
            if (entry.second % totalStrings != 0) {
                return false;
            }
        }

        return true;
    }
};
