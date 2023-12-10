
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        string result;

        // Handle the sign
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }

        long long num = abs(static_cast<long long>(numerator));
        long long den = abs(static_cast<long long>(denominator));

        // Integer part
        result += to_string(num / den);

        // If no fractional part, return result
        if (num % den == 0) {
            return result;
        }

        result += ".";

        unordered_map<long long, int> remainderIndex;
        long long remainder = num % den;

        while (remainder != 0) {
            if (remainderIndex.find(remainder) != remainderIndex.end()) {
                // Repeating part found
                result.insert(remainderIndex[remainder], 1, '(');
                result += ")";
                break;
            }

            remainderIndex[remainder] = result.length();
            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }

        return result;
    }
};

