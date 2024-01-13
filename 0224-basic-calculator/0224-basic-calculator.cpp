
class Solution {
public:
    int calculate(std::string s) {
        std::stack<int> numStack;
        int num = 0;
        int result = 0;
        int sign = 1; 

        for (char c : s) {
            if (std::isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                numStack.push(result);
                numStack.push(sign);

                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                num = 0;

                result *= numStack.top(); numStack.pop();
                result += numStack.top(); numStack.pop();
            }
        }

        result += sign * num;
        return result;
    }
};

