class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagramGroups;
        
        for (const string& str : strs) {
            string sortedStr = str; 
            sort(sortedStr.begin(), sortedStr.end()); 
            
            if (anagramGroups.find(sortedStr) == anagramGroups.end()) {
                anagramGroups[sortedStr] = {str};
            } else {
                anagramGroups[sortedStr].push_back(str);
            }
        }
        
        for (const auto& group : anagramGroups) {
            result.push_back(group.second);
        }
        
        return result;
    }
};
