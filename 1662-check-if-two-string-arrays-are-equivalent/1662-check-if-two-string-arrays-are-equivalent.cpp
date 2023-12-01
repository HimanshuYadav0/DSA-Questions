
class Solution {
public:
    bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
        // Concatenate strings in word1
        std::string concatenatedWord1;
        for (const std::string& s : word1) {
            concatenatedWord1 += s;
        }

        // Concatenate strings in word2
        std::string concatenatedWord2;
        for (const std::string& s : word2) {
            concatenatedWord2 += s;
        }

        // Compare the concatenated strings
        return concatenatedWord1 == concatenatedWord2;
    }
};
