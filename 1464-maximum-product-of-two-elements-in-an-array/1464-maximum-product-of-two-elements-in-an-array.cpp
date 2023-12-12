
class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int n = nums.size();

        // Sort the array in descending order
        std::sort(nums.begin(), nums.end(), std::greater<int>());

        // Calculate the product of the two largest elements after subtracting 1
        return (nums[0] - 1) * (nums[1] - 1);
    }
};
