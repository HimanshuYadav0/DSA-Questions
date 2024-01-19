
class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();

        // Start from the second row and update the minimum falling path sum
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    matrix[i][j] += std::min(matrix[i - 1][j], matrix[i - 1][j + 1]);
                } else if (j == n - 1) {
                    matrix[i][j] += std::min(matrix[i - 1][j], matrix[i - 1][j - 1]);
                } else {
                    matrix[i][j] += std::min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i - 1][j + 1]});
                }
            }
        }

        // Find the minimum falling path sum in the last row
        return *std::min_element(matrix.back().begin(), matrix.back().end());
    }
};
