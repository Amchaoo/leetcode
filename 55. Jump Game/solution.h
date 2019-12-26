#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(),
            reach = 0;

        for (int i = 0; i < n; i++) {
            if (reach < i) {
                return false;
            }

            if (reach >= n) {
                return true;
            }

            reach = max(i + nums[i], reach);
        }

        return true;
    }
};