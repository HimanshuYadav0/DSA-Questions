class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX; // Initialize minimum price to a very large value
        int maxProfit = 0; // Initialize maximum profit to 0
        
        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price; // Update the minimum price if a lower price is found
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice; // Update maxProfit if a higher profit is found
            }
        }
        
        return maxProfit;
    }
};
