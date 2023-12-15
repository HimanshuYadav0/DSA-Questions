
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> outgoingCities;

        // Add the first element of each path to the set
        for (const auto& path : paths) {
            outgoingCities.insert(path[0]);
        }

        // Find the city whose second element is not in the set
        for (const auto& path : paths) {
            if (outgoingCities.find(path[1]) == outgoingCities.end()) {
                return path[1];
            }
        }

        // It is guaranteed that there will always be a destination city,
        // so this line should not be reached.
        return "";
    }
};

