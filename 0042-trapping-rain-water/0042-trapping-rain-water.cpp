
class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0; // It is not possible to trap water with less than 3 bars.

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int trappedWater = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                // Move left pointer and update leftMax
                leftMax = std::max(leftMax, height[left]);
                trappedWater += std::max(0, leftMax - height[left]);
                left++;
            } else {
                // Move right pointer and update rightMax
                rightMax = std::max(rightMax, height[right]);
                trappedWater += std::max(0, rightMax - height[right]);
                right--;
            }
        }

        return trappedWater;
    }
};
