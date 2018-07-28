#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int result;
        int distance = numeric_limits<int>::max();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < size - 2; i++) {
            int frontP = i + 1;
            int endP = size - 1;
            int num1 = nums[i];

            while(frontP < endP) {
                int threeSum = num1 + nums[frontP] + nums[endP];
                int tempDistance = threeSum - target;
                int absTempDistance = abs(tempDistance);

                if (absTempDistance < distance) {
                    distance = absTempDistance;
                    result = threeSum;
                }

                if (tempDistance < 0) {
                    while(frontP < endP && nums[frontP] == nums[++frontP]);
                } else if (tempDistance >0) {
                    while(endP > frontP && nums[endP] == nums[--endP]);
                }

                if (tempDistance == 0) {
                    return num1 + nums[frontP] + nums[endP];
                }
            }
        }

        return result;
    }
};