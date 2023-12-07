
class Solution {
public:
    int maximumGap(std::vector<int>& nums) {
        int n = nums.size();

        if (n < 2) {
            return 0;
        }

        int maxNum = *max_element(nums.begin(), nums.end());

        int exp = 1;
        std::vector<int> output(n);
        
        while (maxNum / exp > 0) {
            radixSort(nums, n, exp, output);
            std::swap(nums, output);
            exp *= 10;
        }

        int maxDiff = 0;
        for (int i = 1; i < n; ++i) {
            maxDiff = std::max(maxDiff, nums[i] - nums[i - 1]);
        }

        return maxDiff;
    }

private:
    void radixSort(std::vector<int>& nums, int n, int exp, std::vector<int>& output) {
        const int radix = 10;
        std::vector<int> count(radix, 0);

        for (int i = 0; i < n; ++i) {
            count[(nums[i] / exp) % radix]++;
        }

        for (int i = 1; i < radix; ++i) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; --i) {
            output[count[(nums[i] / exp) % radix] - 1] = nums[i];
            count[(nums[i] / exp) % radix]--;
        }
    }
};
