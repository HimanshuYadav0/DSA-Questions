class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndices; // Map to store numbers and their indices
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numIndices.find(complement) != numIndices.end()) {
                // Found the complement, return the indices
                return {numIndices[complement], i};
            }
            // Store the current number and its index
            numIndices[nums[i]] = i;
        }
        
        // If no solution is found, return an empty vector
        return {};
    }
};
