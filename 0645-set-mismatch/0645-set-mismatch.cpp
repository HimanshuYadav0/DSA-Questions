
class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(2, 0);
        std::vector<int> count(n + 1, 0);

        for (int num : nums) {
            count[num]++;
            if (count[num] == 2) {
                result[0] = num;  // Duplicate number
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (count[i] == 0) {
                result[1] = i;  // Missing number
                break;
            }
        }

        return result;
    }
};
