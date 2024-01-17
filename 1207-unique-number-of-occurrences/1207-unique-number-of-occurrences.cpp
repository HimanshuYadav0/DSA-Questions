
class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::unordered_map<int, int> frequencyMap;
        std::unordered_set<int> uniqueFrequencies;

        for (int num : arr) {
            frequencyMap[num]++;
        }

        for (const auto& entry : frequencyMap) {
            if (!uniqueFrequencies.insert(entry.second).second) {
                return false;
            }
        }

        return true;
    }
};
