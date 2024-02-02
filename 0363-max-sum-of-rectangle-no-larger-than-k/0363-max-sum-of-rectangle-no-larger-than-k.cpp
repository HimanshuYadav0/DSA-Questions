
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = INT_MIN;

        for (int left = 0; left < n; left++) {
            vector<int> sums(m, 0);

            for (int right = left; right < n; right++) {
                for (int i = 0; i < m; i++) {
                    sums[i] += matrix[i][right];
                }

                set<int> prefixSums;
                prefixSums.insert(0);
                int currentSum = 0, maxSum = INT_MIN;

                for (int sum : sums) {
                    currentSum += sum;
                    auto it = prefixSums.lower_bound(currentSum - k);

                    if (it != prefixSums.end()) {
                        maxSum = max(maxSum, currentSum - *it);
                    }

                    prefixSums.insert(currentSum);
                }

                result = max(result, maxSum);
            }
        }

        return result;
    }
};
