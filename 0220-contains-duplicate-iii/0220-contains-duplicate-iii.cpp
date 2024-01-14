
class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff) {
        if (indexDiff <= 0 || valueDiff < 0) {
            return false;
        }

        std::set<long long> window; // Using long long to avoid overflow

        for (int i = 0; i < nums.size(); ++i) {
            if (i > indexDiff) {
                window.erase(nums[i - indexDiff - 1]);
            }

            auto it = window.lower_bound((long long)nums[i] - valueDiff);

            if (it != window.end() && std::abs(*it - nums[i]) <= valueDiff) {
                return true;
            }

            window.insert(nums[i]);
        }

        return false;
    }
};
