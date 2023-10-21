class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        
        int left = findLeftBoundary(nums, target);
        int right = findRightBoundary(nums, target);
        
        if (left <= right) {
            result[0] = left;
            result[1] = right;
        }
        
        return result;
    }
    
    int findLeftBoundary(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int index = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                index = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return index;
    }
    
    int findRightBoundary(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int index = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                index = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return index;
    }
};
