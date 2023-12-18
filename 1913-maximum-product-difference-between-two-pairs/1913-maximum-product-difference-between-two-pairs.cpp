
class Solution {
public:
    int maxProductDifference(std::vector<int>& nums) {
        // Sort the array in ascending order
        std::sort(nums.begin(), nums.end());
        
        // Calculate the product difference
        int n = nums.size();
        int maxProduct = nums[n - 1] * nums[n - 2];
        int minProduct = nums[0] * nums[1];
        
        // Return the result
        return maxProduct - minProduct;
    }
};
