class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end()); // Sort the candidates to easily skip duplicates.
        backtrack(result, candidates, current, 0, target);
        return result;
    }
    
    void backtrack(vector<vector<int>>& result, vector<int>& candidates, vector<int>& current, int start, int target) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue; 
            }
            if (candidates[i] > target) {
                break; 
            }
            current.push_back(candidates[i]); 
            backtrack(result, candidates, current, i + 1, target - candidates[i]);
            current.pop_back(); 
        }
    }
};
