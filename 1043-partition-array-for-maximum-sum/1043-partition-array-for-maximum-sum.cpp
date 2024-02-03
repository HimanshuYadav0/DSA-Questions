
class Solution {
public:
    int maxSumAfterPartitioning(std::vector<int>& arr, int k) {
        int n = arr.size();
        std::vector<int> dp(n, 0);

        for (int i = 0; i < n; ++i) {
            int max_val = 0;
            for (int j = 1; j <= k && i - j + 1 >= 0; ++j) {
                max_val = std::max(max_val, arr[i - j + 1]);
                dp[i] = std::max(dp[i], (i >= j ? dp[i - j] : 0) + max_val * j);
            }
        }

        return dp[n - 1];
    }
};
