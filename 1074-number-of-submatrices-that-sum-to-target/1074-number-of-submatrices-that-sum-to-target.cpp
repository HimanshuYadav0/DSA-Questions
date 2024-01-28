
class Solution {
public:
    int numSubmatrixSumTarget(std::vector<std::vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int result = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        for (int y1 = 0; y1 < cols; ++y1) {
            for (int y2 = y1; y2 < cols; ++y2) {
                std::unordered_map<int, int> prefixSumCount;
                prefixSumCount[0] = 1;
                int currentSum = 0;

                // Iterate through all pairs of rows and compute submatrix sum
                for (int x = 0; x < rows; ++x) {
                    int submatrixSum = matrix[x][y2] - (y1 > 0 ? matrix[x][y1 - 1] : 0);
                    currentSum += submatrixSum;

                    if (prefixSumCount.find(currentSum - target) != prefixSumCount.end()) {
                        result += prefixSumCount[currentSum - target];
                    }

                    prefixSumCount[currentSum]++;
                }
            }
        }

        return result;
    }
};
