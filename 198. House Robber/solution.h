#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();

        if (size == 0) {
            return 0;
        }
        else if (size == 1) {
            return nums[0];
        }

        vector<int> f(size, 0);
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);

        for (int i = 2; i < size; i++) {
            for (int j = 0; j < i - 1; j++) {
                f[i] = max(f[i], f[j] + nums[i]);
            }
        }

        return max(f[size - 1], f[size - 2]);
    }
};