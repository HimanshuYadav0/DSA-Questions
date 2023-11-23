#include <vector>
#include <algorithm>

class Solution {
public:
    bool isArithmetic(std::vector<int>& subarray) {
        if (subarray.size() < 2) {
            return false;
        }
        std::sort(subarray.begin(), subarray.end());
        int diff = subarray[1] - subarray[0];
        for (int i = 2; i < subarray.size(); ++i) {
            if (subarray[i] - subarray[i - 1] != diff) {
                return false;
            }
        }
        return true;
    }
    
    std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l, std::vector<int>& r) {
        std::vector<bool> result;
        for (int i = 0; i < l.size(); ++i) {
            std::vector<int> subarray(nums.begin() + l[i], nums.begin() + r[i] + 1);
            result.push_back(isArithmetic(subarray));
        }
        return result;
    }
};
