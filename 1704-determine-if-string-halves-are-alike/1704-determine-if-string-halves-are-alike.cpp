
class Solution {
public:
    bool halvesAreAlike(std::string s) {
        int n = s.length();
        int mid = n / 2;
        
        auto countVowels = [](const std::string& str) {
            std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
            int count = 0;
            for (char c : str) {
                if (vowels.count(c) > 0) {
                    count++;
                }
            }
            return count;
        };
        
        int countA = countVowels(s.substr(0, mid));
        int countB = countVowels(s.substr(mid));
        
        return countA == countB;
    }
};
