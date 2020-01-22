// buyMax表示第i天, 进行t次买入交易, 所得的金额最大值
// sellMax表示第i天, 进行t次卖出交易, 所得的金额最大值

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();

        if (size < 2) {
            return 0;
        }

        vector<vector<int>> buyMax(size + 1, vector<int>(3, 0));
        vector<vector<int>> sellMax(size + 1, vector<int>(3, 0));

        buyMax[0][1] = -prices[0];
        buyMax[0][2] = -prices[0];

        for (int i = 1; i <= size; i++) {
            for (int t = 1; t <= 2; t++) {
                buyMax[i][t] = max(buyMax[i - 1][t], sellMax[i - 1][t - 1] - prices[i - 1]);
                sellMax[i][t] = max(sellMax[i - 1][t], buyMax[i - 1][t] + prices[i - 1]);
            }
        }

        return sellMax[size][2];
    }
};