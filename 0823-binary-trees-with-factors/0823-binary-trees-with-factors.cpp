class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int MOD = 1000000007;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        unordered_map<int, long long> dp; 
        long long totalTrees = 0;
        
        for (int i = 0; i < n; i++) {
            dp[arr[i]] = 1;
            
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int factor = arr[i] / arr[j];
                    if (dp.count(factor)) {
                        dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[factor]) % MOD;
                    }
                }
            }
            
            totalTrees = (totalTrees + dp[arr[i]]) % MOD;
        }
        
        return totalTrees;
    }
};
