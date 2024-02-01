#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 3) {
            vector<int> currentArray;

            for (int j = i; j < min(i + 3, static_cast<int>(nums.size())); ++j) {
                currentArray.push_back(nums[j]);
            }

            // Check the conditions for each pair of elements in the current array
            for (int x = 0; x < currentArray.size() - 1; ++x) {
                for (int y = x + 1; y < currentArray.size(); ++y) {
                    if (currentArray[y] - currentArray[x] > k) {
                        // If the conditions are not satisfied, return an empty array
                        return {};
                    }
                }
            }

            result.push_back(currentArray);
        }

        return result;
    }
};
