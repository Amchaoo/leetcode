class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int max = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < min) {
                min = max = prices[i];
            }

            if (prices[i] > max) {
                max = prices[i];
            }

            profit = max(max - min, profit);
        }
    }
};