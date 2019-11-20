#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();

        if (size == 0 || size == 1) {
            return size;
        }

        int i = 0;

        for (auto num: nums) {
            if (nums[i] != num) {
                nums[++i] = num;
            }
        }

        return i + 1;
    }
};