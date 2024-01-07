
class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        int n = nums.size();
        int result = 0;


        std::vector<std::unordered_map<long long, int>> dp(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - nums[j];

                result += dp[j][diff];
                dp[i][diff] += (1 + dp[j][diff]);
            }
        }

        return result;
    }
};
