#include <vector>
#include <algorithm>

class Solution {
public:
    int largestSubmatrix(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Calculate the maximum height of consecutive 1's ending at each cell
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }
        
        int result = 0;
        
        // For each row, sort the heights and calculate the area of the largest rectangle
        for (int i = 0; i < m; ++i) {
            std::sort(matrix[i].begin(), matrix[i].end());
            for (int j = n - 1; j >= 0; --j) {
                result = std::max(result, matrix[i][j] * (n - j));
            }
        }
        
        return result;
    }
};
