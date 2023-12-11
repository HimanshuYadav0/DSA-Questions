

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
        std::vector<std::string> result;
        std::unordered_set<std::string> seen;
        std::unordered_set<std::string> repeated;

        // Check if the input is valid
        if (s.length() < 10) {
            return result;
        }

        // Iterate through the string with a sliding window of size 10
        for (int i = 0; i <= s.length() - 10; ++i) {
            std::string sequence = s.substr(i, 10);

            // Check if the sequence is in the seen set
            if (seen.find(sequence) == seen.end()) {
                seen.insert(sequence);
            } else {
                // If already seen, add to the repeated set
                repeated.insert(sequence);
            }
        }

        // Convert the repeated set to a vector
        result.assign(repeated.begin(), repeated.end());

        return result;
    }
};
