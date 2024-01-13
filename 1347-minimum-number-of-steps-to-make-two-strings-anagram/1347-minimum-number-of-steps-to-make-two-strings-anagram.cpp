class Solution {
public:
    int minSteps(std::string s, std::string t) {
        std::unordered_map<char, int> freqS, freqT;
        
        for (char c : s) {
            freqS[c]++;
        }
        
        for (char c : t) {
            freqT[c]++;
        }
        
        int steps = 0;
        for (auto& entry : freqS) {
            char c = entry.first;
            steps += std::max(0, freqS[c] - freqT[c]);
        }
        
        return steps;
    }
};
