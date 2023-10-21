class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesesHelper("", n, n, result);
        return result;
    }
    
    void generateParenthesesHelper(string current, int open, int close, vector<string>& result) {
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }
        
        if (open > 0) {
            generateParenthesesHelper(current + "(", open - 1, close, result);
        }
        
        if (close > open) {
            generateParenthesesHelper(current + ")", open, close - 1, result);
        }
    }
};
