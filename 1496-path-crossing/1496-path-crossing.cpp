
class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> visited;  // Store visited points
        visited.insert({0, 0});      // Starting point

        int x = 0, y = 0;

        for (char direction : path) {
            // Update the current position based on the direction
            if (direction == 'N') {
                y++;
            } else if (direction == 'S') {
                y--;
            } else if (direction == 'E') {
                x++;
            } else if (direction == 'W') {
                x--;
            }

            // Check if the current position has been visited before
            if (visited.count({x, y}) > 0) {
                return true;
            }

            // Mark the current position as visited
            visited.insert({x, y});
        }

        return false;
    }
};

