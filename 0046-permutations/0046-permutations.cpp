class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentPermutation;
        vector<bool> used(nums.size(), false); // To keep track of used elements

        generatePermutations(nums, used, currentPermutation, result);
        
        return result;
    }

private:
    void generatePermutations(vector<int>& nums, vector<bool>& used, vector<int>& currentPermutation, vector<vector<int>>& result) {
        if (currentPermutation.size() == nums.size()) {
            result.push_back(currentPermutation);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                currentPermutation.push_back(nums[i]);
                generatePermutations(nums, used, currentPermutation, result);
                currentPermutation.pop_back();
                used[i] = false;
            }
        }
    }
};
