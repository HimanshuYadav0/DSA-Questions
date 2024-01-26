#include <vector>
#include <string>

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string expression;
        backtrack(num, target, 0, 0, 0, expression, result);
        return result;
    }

private:
    void backtrack(const string& num, int target, int index, long long currentEval, long long prevNum, string expression, vector<string>& result) {
        if (index == num.length()) {
            if (currentEval == target) {
                result.push_back(expression);
            }
            return;
        }

        for (int i = index; i < num.length(); ++i) {
            if (i > index && num[index] == '0') {
                // Avoid leading zeros in operands
                break;
            }

            string currentStr = num.substr(index, i - index + 1);
            long long currentNum = stoll(currentStr);

            if (index == 0) {
                // First operand, no operator is used yet
                backtrack(num, target, i + 1, currentNum, currentNum, currentStr, result);
            } else {
                // Try all operators: '+', '-', '*'
                backtrack(num, target, i + 1, currentEval + currentNum, currentNum, expression + "+" + currentStr, result);
                backtrack(num, target, i + 1, currentEval - currentNum, -currentNum, expression + "-" + currentStr, result);
                backtrack(num, target, i + 1, currentEval - prevNum + prevNum * currentNum, prevNum * currentNum, expression + "*" + currentStr, result);
            }
        }
    }
};
