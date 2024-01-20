
class Solution {
public:
    int sumSubarrayMins(std::vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        std::stack<int> stk; // Stack to store indices
        std::vector<int> left(n), right(n);

        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[i] < arr[stk.top()]) {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        while (!stk.empty()) {
            stk.pop();
        }

        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[i] <= arr[stk.top()]) {
                stk.pop();
            }
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        long long result = 0;
        for (int i = 0; i < n; ++i) {
            result = (result + static_cast<long long>(arr[i]) * (i - left[i]) * (right[i] - i)) % MOD;
        }

        return static_cast<int>(result);
    }
};
