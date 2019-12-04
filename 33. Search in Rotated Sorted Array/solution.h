#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();

        if (size == 0) {
            return -1;
        }

        int left = 0;
        int right = size - 1;
        int medium;
        int beginValue = nums[left];
        int endValue = nums[right];
        bool maybeFoundInLeft = beginValue <= target;

        while (true) {
            if (left > right || left < 0 || right >= nums.size()) {
                return -1;
            }

            medium = getMedium(left, right);
            int mediumValue = nums[medium];
            bool locateInLeft = mediumValue >= beginValue;

            if (mediumValue == target) {
                return medium;
            }
            else if (mediumValue < target) {
                if (locateInLeft) {
                    left = medium + 1;
                }
                else {
                    if (maybeFoundInLeft) {
                        right = medium - 1;
                    }
                    else {
                        left = medium + 1;
                    }
                }
            }
            else if (mediumValue > target) {
                if (locateInLeft) {
                    if (maybeFoundInLeft) {
                        right = medium - 1;
                    }
                    else {
                        left = medium + 1;
                    }
                }
                else {
                    right = medium - 1;
                }
            }
        }
    }
private:
    int getMedium(int l, int r) {
        return ceil(l + (r - l) / 2);
    }
};