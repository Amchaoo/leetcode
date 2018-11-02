#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int startPoint, endPoint;
        vector<vector<int>> result = {};

        for (int i = 0; i < size - 3;) {
            for (int j = i + 1; j < size - 2;) {

                int newTarget = target - nums[i] - nums[j];
                int nowSum;
                startPoint = j + 1;
                endPoint = size - 1;

                while (startPoint < endPoint) {
                    nowSum = nums[startPoint] + nums[endPoint];

                    if (nowSum < newTarget) {
                        while(nums[startPoint] == nums[++startPoint]);
                    }
                    else if (nowSum > newTarget) {
                        while(nums[endPoint] == nums[--endPoint]);
                    }
                    else {
                        result.push_back({nums[i], nums[j], nums[startPoint], nums[endPoint]});
                        while(nums[startPoint] == nums[++startPoint]);
                        while(nums[endPoint] == nums[--endPoint]);
                    }
                }

                while(nums[j] == nums[++j]);
            }
            while(nums[i] == nums[++i]);
        }

        return result;
    }
};