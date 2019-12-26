#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int maxSum = nums[0],
            curSum = nums[0],
            size = nums.size();

        for (int i = 1; i < size; i++) {
            if (curSum > 0) {
                curSum += nums[i];
            }
            else {
                curSum = nums[i];
            }

            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};