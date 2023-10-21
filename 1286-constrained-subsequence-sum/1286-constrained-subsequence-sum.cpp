#include <vector>
#include <deque>

class Solution {
public:
    int constrainedSubsetSum(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> dp(n);

        std::deque<int> dq;  

        int maxSum = nums[0];
        dp[0] = nums[0];
        dq.push_back(0);

        for (int i = 1; i < n; i++) {
            while (!dq.empty() && i - dq.front() > k) {
                dq.pop_front();
            }

            dp[i] = std::max(nums[i], nums[i] + dp[dq.front()]);
            while (!dq.empty() && dp[i] >= dp[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);

            maxSum = std::max(maxSum, dp[i]);
        }

        return maxSum;
    }
};

