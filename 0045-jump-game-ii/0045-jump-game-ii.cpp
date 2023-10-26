class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int curMax = 0; 
        int nextMax = 0; 

        for (int i = 0; i < n - 1; i++) {
            nextMax = max(nextMax, i + nums[i]);
            if (i == curMax) {
                jumps++;
                curMax = nextMax;
            }
        }

        return jumps;
    }
};
