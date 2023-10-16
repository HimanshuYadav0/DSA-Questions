class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        
        // Initialize an array to store the number of ways to reach each step.
        vector<int> dp(n + 1, 0);
        
        // There are 2 ways to reach the first and second steps.
        dp[1] = 1;
        dp[2] = 2;
        
        // Calculate the number of ways to reach each step from step 3 to n.
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        // The result is stored in dp[n].
        return dp[n];
    }
};
