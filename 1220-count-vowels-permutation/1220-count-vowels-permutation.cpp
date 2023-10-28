class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = 1000000007;
        
        // Create a 2D DP array
        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
        
        // Initialize the base case
        for (int i = 0; i < 5; i++) {
            dp[1][i] = 1;
        }
        
        // Define the rules for transitions
        // a -> e
        // e -> a, i
        // i -> a, e, o, u
        // o -> i, u
        // u -> a
        for (int i = 2; i <= n; i++) {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % MOD;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
            dp[i][3] = dp[i - 1][2];
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        }
        
        // Sum up the values in the last row to get the result
        long long result = 0;
        for (int i = 0; i < 5; i++) {
            result = (result + dp[n][i]) % MOD;
        }
        
        return static_cast<int>(result);
    }
};
