class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int k = 1; // Initialize the unique element count
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i]; // Overwrite duplicates with unique elements
                k++;
            }
        }
        
        return k;
    }
};
