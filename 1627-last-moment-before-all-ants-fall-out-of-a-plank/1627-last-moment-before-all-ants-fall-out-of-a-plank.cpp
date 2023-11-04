class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxTime = 0;
        
        // Calculate the time for ants on the left to fall off the plank.
        for (int i = 0; i < left.size(); i++) {
            maxTime = max(maxTime, left[i]);
        }
        
        // Calculate the time for ants on the right to fall off the plank.
        for (int i = 0; i < right.size(); i++) {
            maxTime = max(maxTime, n - right[i]);
        }
        
        return maxTime;
    }
};
