

class Solution {
public:
    int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        int maxWidth = 0;

        for (int i = 1; i < points.size(); ++i) {
            int verticalDistance = points[i][0] - points[i - 1][0];

            maxWidth = std::max(maxWidth, verticalDistance);
        }

        return maxWidth;
    }
};
