
class Solution {
public:
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        
        std::sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) {
            return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
        });

        std::vector<int> lis;

        for (const auto& envelope : envelopes) {
            auto it = std::lower_bound(lis.begin(), lis.end(), envelope[1]);
            if (it == lis.end()) {
                lis.push_back(envelope[1]);
            } else {
                *it = envelope[1];
            }
        }

        return lis.size();
    }
};
