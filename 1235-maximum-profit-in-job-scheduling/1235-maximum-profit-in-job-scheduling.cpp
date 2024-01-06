#include <vector>
#include <algorithm>

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> jobs;

        // Combine information into a jobs array
        for (int i = 0; i < n; ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        // Sort jobs based on end time
        sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
            return get<1>(a) < get<1>(b);
        });

        // Initialize dp array
        vector<int> dp(n, 0);

        // Base case
        dp[0] = get<2>(jobs[0]);

        // Iterate through jobs and update dp array
        for (int i = 1; i < n; ++i) {
            // Binary search to find the latest job that doesn't overlap with the current job
            int low = 0, high = i - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (get<1>(jobs[mid]) <= get<0>(jobs[i])) {
                    if (get<1>(jobs[mid + 1]) <= get<0>(jobs[i])) {
                        low = mid + 1;
                    } else {
                        dp[i] = max(dp[mid] + get<2>(jobs[i]), dp[i - 1]);
                        break;
                    }
                } else {
                    high = mid - 1;
                }
            }

            // If no non-overlapping job is found
            if (low > high) {
                dp[i] = max(get<2>(jobs[i]), dp[i - 1]);
            }
        }

        // The final answer is the maximum value in the dp array
        return dp[n - 1];
    }
};
