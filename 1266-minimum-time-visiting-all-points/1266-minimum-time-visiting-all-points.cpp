
class Solution {
public:
    int minTimeToVisitAllPoints(const std::vector<std::vector<int>>& points) {
        int totalTime = 0;
        
        for (int i = 1; i < points.size(); ++i) {
            int xDiff = std::abs(points[i][0] - points[i - 1][0]);
            int yDiff = std::abs(points[i][1] - points[i - 1][1]);
            
            // Calculate the time to move diagonally
            int diagonalTime = std::min(xDiff, yDiff);
            
            // Calculate the remaining time to move horizontally or vertically
            int remainingTime = std::abs(xDiff - yDiff);
            
            // Total time is the sum of diagonal time and remaining time
            totalTime += diagonalTime + remainingTime;
        }
        
        return totalTime;
    }
};
