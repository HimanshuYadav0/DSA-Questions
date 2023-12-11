
class Solution {
public:
    int findSpecialInteger(std::vector<int>& arr) {
        int n = arr.size();
        int targetFrequency = n / 4 + 1;  // 25% of the array length plus 1

        int currentElement = arr[0];
        int currentFrequency = 1;

        for (int i = 1; i < n; ++i) {
            if (arr[i] == currentElement) {
                currentFrequency++;
                if (currentFrequency >= targetFrequency) {
                    return currentElement;
                }
            } else {
                currentElement = arr[i];
                currentFrequency = 1;
            }
        }

        // If the loop finishes without finding the result, return the last element
        return currentElement;
    }
};
