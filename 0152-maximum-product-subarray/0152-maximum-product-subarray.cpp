#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();

        // Initialize variables to store the maximum and minimum product ending at the current index
        int maxEndingHere = nums[0];
        int minEndingHere = nums[0];

        // Initialize the result to the maximum product
        int result = nums[0];

        for (int i = 1; i < n; ++i) {
            // If the current number is negative, swap maxEndingHere and minEndingHere
            if (nums[i] < 0) {
                std::swap(maxEndingHere, minEndingHere);
            }

            // Update maxEndingHere and minEndingHere based on the current number
            maxEndingHere = std::max(nums[i], maxEndingHere * nums[i]);
            minEndingHere = std::min(nums[i], minEndingHere * nums[i]);

            // Update the overall result
            result = std::max(result, maxEndingHere);
        }

        return result;
    }
};
