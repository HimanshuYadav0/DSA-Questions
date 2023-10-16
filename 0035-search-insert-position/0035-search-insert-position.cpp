class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2; // Calculate the middle index
            
            if (nums[mid] == target) {
                return mid; // Target found at the middle index
            } else if (nums[mid] < target) {
                left = mid + 1; // Adjust the left boundary
            } else {
                right = mid - 1; // Adjust the right boundary
            }
        }
        
        // If the loop terminates, 'left' will be the index where the target should be inserted
        return left;
    }
};
