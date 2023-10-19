class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result, candidates, current, 0, target);
        return result;
    }
    
    void backtrack(vector<vector<int>>& result, vector<int>& candidates, vector<int>& current, int start, int target) {
        if (target < 0) {
            return; 
        }
        if (target == 0) {
            result.push_back(current); 
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]); 
            backtrack(result, candidates, current, i, target - candidates[i]);
            current.pop_back();
        }
    }
};
