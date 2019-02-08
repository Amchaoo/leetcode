#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        map<int, int> dp = {};

        for (int i = 1; i < 366; i++) {
            if (find(days.begin(), days.end(), i) == days.end()) {
                dp[i] = i - 1 > 0 ? dp[i - 1] : 0;
            }
            else {
                dp[i] = min({
                    (i - 1 > 0 ? dp[i - 1] : 0) + costs[0],
                    (i - 7 > 0 ? dp[i - 7] : 0) + costs[1],
                    (i - 30 > 0 ? dp[i - 30] : 0) + costs[2]
                });
            }
        }

        return dp[365];
    }
};