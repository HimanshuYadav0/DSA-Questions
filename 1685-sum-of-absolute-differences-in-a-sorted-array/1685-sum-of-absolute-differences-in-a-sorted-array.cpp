#include <vector>

class Solution {
public:
    std::vector<int> getSumAbsoluteDifferences(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n, 0);

        // Calculate prefix sum array
        std::vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        // Calculate result array
        for (int i = 0; i < n; ++i) {
            int leftSum = i * nums[i] - (i > 0 ? prefixSum[i - 1] : 0);
            int rightSum = (prefixSum[n - 1] - prefixSum[i]) - (n - i - 1) * nums[i];
            result[i] = leftSum + rightSum;
        }

        return result;
    }
};
