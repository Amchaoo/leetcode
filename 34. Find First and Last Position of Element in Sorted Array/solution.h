#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos = binnarySearch(nums, target);
        vector<int> res = {-1, -1};

        if (pos != -1) {
            int l = pos;
            int r = pos;

            while (++r < nums.size()) {
                if (nums[r] != target) {
                    break;
                }
            }

            while (--l >= 0) {
                if (nums[l] != target) {
                    break;
                }
            }

            res[0] = ++l;
            res[1] = --r;
        }

        return res;
    }
private:
    int binnarySearch(vector<int>& nums, int target) {
        int size = nums.size();
        int l = 0;
        int r = size - 1;
        int m;

        if (size == 0) {
            return -1;
        }

        while (true) {
            if (l > r || l < 0 || r >= size) {
                return -1;
            }

            m = l + ceil((r - l) / 2);

            if (nums[m] > target) {
                r = m - 1;
            }
            else if (nums[m] < target) {
                l = m + 1;
            }
            else {
                return m;
            }
        }
    }
};