class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        if (divisor == INT_MIN)
            return dividend == INT_MIN ? 1 : 0;

        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        long long ldividend = abs((long long)dividend);
        long long ldivisor = abs((long long)divisor);
        
        int result = 0;
        while (ldividend >= ldivisor) {
            long long temp = ldivisor, multiple = 1;
            while (ldividend >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            ldividend -= temp;
            result += multiple;
        }
        
        return result * sign;
    }
};
