#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int index = size - 1;
        bool isBiggest = true;

        while (index > 0) {
            if (nums[index - 1] >= nums[index]) {
                index--;
                continue;
            }

            isBiggest = false;

            int tmp = nums[index - 1];
            int innerIndex = size - 1;

            while (innerIndex >= index) {
                if (nums[innerIndex] > tmp) {
                    nums[index - 1] = nums[innerIndex];
                    nums[innerIndex] = tmp;
                    reverse(nums.begin() + index, nums.end());
                    break;
                }

                innerIndex--;
            }

            index--;
            break;
        }

        if (isBiggest) {
            reverse(nums.begin(), nums.end());
        }
    }
};