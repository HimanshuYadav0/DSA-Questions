class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<int> queens(n, -1); 
        
        solveNQueensHelper(queens, 0, count);
        
        return count;
    }

private:
    void solveNQueensHelper(vector<int>& queens, int row, int& count) {
        int n = queens.size();
        
        if (row == n) {
            count++; 
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (isSafe(queens, row, col)) {
                queens[row] = col;
                solveNQueensHelper(queens, row + 1, count);
                queens[row] = -1;
            }
        }
    }

    bool isSafe(const vector<int>& queens, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }
};
