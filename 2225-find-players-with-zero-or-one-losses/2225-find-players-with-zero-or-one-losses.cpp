
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losses;
        set<int> players;

        for (const auto& match : matches) {
            players.insert(match[0]);
            players.insert(match[1]);
            losses[match[1]]++;
        }

        vector<int> noLoss;
        vector<int> oneLoss;

        for (const auto& player : players) {
            if (losses[player] == 0) {
                noLoss.push_back(player);
            } else if (losses[player] == 1) {
                oneLoss.push_back(player);
            }
        }

        return {noLoss, oneLoss};
    }
};
