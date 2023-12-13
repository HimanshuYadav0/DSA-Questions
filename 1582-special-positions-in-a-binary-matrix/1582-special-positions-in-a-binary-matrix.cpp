#include <vector>

class Solution {
public:
    int numSpecial(std::vector<std::vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    bool isSpecial = true;

                    // Check the row (i)
                    for (int k = 0; k < n; ++k) {
                        if (k != j && mat[i][k] == 1) {
                            isSpecial = false;
                            break;
                        }
                    }

                    // Check the column (j)
                    for (int k = 0; k < m; ++k) {
                        if (k != i && mat[k][j] == 1) {
                            isSpecial = false;
                            break;
                        }
                    }

                    if (isSpecial) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
