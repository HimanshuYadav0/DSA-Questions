class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0) {
            return result;
        }
        
        // First row is always [1]
        result.push_back({1});
        
        for (int i = 1; i < numRows; i++) {
            vector<int> row;
            row.push_back(1);  // First element in each row is 1
            
            // Fill the row with values based on the previous row
            for (int j = 1; j < i; j++) {
                row.push_back(result[i-1][j-1] + result[i-1][j]);
            }
            
            row.push_back(1);  // Last element in each row is 1
            
            result.push_back(row);
        }
        
        return result;
    }
};
