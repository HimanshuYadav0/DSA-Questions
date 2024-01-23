
class Solution {
public:
    int maxLength(std::vector<std::string>& arr) {
        int maxLength = 0;
        std::vector<std::string> validSubsequences;

        backtrack(arr, 0, "", validSubsequences, maxLength);

        return maxLength;
    }

private:
    void backtrack(const std::vector<std::string>& arr, int index, const std::string& current, std::vector<std::string>& validSubsequences, int& maxLength) {
        if (isUnique(current)) {
            maxLength = std::max(maxLength, static_cast<int>(current.size()));
        } else {
            return;  
        }
        for (int i = index; i < arr.size(); ++i) {
            std::string newSubsequence = current + arr[i];
            backtrack(arr, i + 1, newSubsequence, validSubsequences, maxLength);
        }
    }

    bool isUnique(const std::string& s) {
        std::unordered_set<char> charSet;
        for (char c : s) {
            if (charSet.count(c) > 0) {
                return false;  // Not unique
            }
            charSet.insert(c);
        }
        return true;  // Unique
    }
};
