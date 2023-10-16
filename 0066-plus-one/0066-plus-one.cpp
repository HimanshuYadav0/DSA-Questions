class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1; // Initialize the carry to 1 to add one.

        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;

            // If there's no more carry, we can exit early.
            if (carry == 0) {
                break;
            }
        }

        // If there's still a carry, it means we need to add an additional digit at the front.
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};
