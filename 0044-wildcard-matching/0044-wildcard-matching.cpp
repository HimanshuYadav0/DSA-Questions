
class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.length();
        int n = p.length();

        // Create a DP table with size (m+1) x (n+1)
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        // Empty pattern matches empty string
        dp[0][0] = true;

        // Handle patterns with '*' at the beginning
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    // '*' can match either 0 characters or 1 character
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    // '?' matches any single character, or characters match
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        // The result is stored in the bottom-right cell of the DP table
        return dp[m][n];
    }
};
