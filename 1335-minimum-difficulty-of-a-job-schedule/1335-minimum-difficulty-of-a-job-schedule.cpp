#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
    int minDifficulty(std::vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        if (n < d) {
            return -1;
        }
        
        std::vector<std::vector<int>> dp(d + 1, std::vector<int>(n + 1, INT_MAX));
        dp[0][0] = 0;
        
        for (int i = 1; i <= d; ++i) {
            for (int j = 1; j <= n; ++j) {
                int maxDifficulty = 0;
                for (int k = j - 1; k >= i - 1; --k) {
                    maxDifficulty = std::max(maxDifficulty, jobDifficulty[k]);
                    if (dp[i - 1][k] != INT_MAX) {
                        dp[i][j] = std::min(dp[i][j], dp[i - 1][k] + maxDifficulty);
                    }
                }
            }
        }
        
        return dp[d][n] == INT_MAX ? -1 : dp[d][n];
    }
};
