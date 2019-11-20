#include <vector>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;

        for (auto num: nums) {
            if (num == val) {
                continue;
            }

            nums[i++] = num;
        }

        return i;
    }
};