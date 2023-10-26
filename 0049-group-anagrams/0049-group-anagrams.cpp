class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end()); 
            anagramGroups[sortedStr].push_back(str);
        }
        
        vector<vector<string>> result;
        for (auto it = anagramGroups.begin(); it != anagramGroups.end(); ++it) {
            result.push_back(it->second);
        }
        
        return result;
    }
};
