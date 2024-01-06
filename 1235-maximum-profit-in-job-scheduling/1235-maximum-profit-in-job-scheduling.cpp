
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> jobs;


        for (int i = 0; i < n; ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }


        sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
            return get<1>(a) < get<1>(b);
        });


        vector<int> dp(n, 0);

        // Base case
        dp[0] = get<2>(jobs[0]);

        for (int i = 1; i < n; ++i) {
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

            if (low > high) {
                dp[i] = max(get<2>(jobs[i]), dp[i - 1]);
            }
        }

        return dp[n - 1];
    }
};
