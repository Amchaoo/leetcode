#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> result = {};

        if (size < 3) {
            return result;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < size - 2; i++) {
            int valOne = -nums[i];
            int frontIndex = i + 1;
            int endIndex = size - 1;
            int sum = 0;

            while (endIndex > frontIndex) {
                sum = nums[frontIndex] + nums[endIndex];

                if (sum > valOne) {
                    endIndex--;
                } else if (sum < valOne) {
                    frontIndex++;
                } else {
                    vector<int> hittedValues(3, 0);
                    hittedValues[0] = -valOne;
                    hittedValues[1] = nums[frontIndex];
                    hittedValues[2] = nums[endIndex];
                    result.push_back(hittedValues);
                    
                    while(nums[endIndex] == nums[--endIndex]);
                    while(nums[frontIndex] == nums[++frontIndex]);
                }
            }     

            while(nums[i] == nums[i + 1]) i++;   
        }

        return result;
    }
};