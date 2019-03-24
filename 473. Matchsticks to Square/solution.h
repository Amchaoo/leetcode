#include<vector>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = 0;
        for (int num: nums) sum += num;
        if (sum % 4 != 0) return false;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        return dfs(nums, new int[4](), 0, sum / 4);
    }

    bool dfs(vector<int>& nums, int containers[], int index, int target) {
        if (
            index == nums.size()
            && containers[0] == target
            && containers[1] == target
            && containers[2] == target
        ) return true;

        for (int i = 0; i < 4; i++) {
            if (containers[i] + nums[index] > target) continue;

            int j = i;
            while (--j >= 0)
                // 和前面的值做比较, 如果有相同的 说明必然return false, 没必要在判断了
                if (containers[i] == containers[j])
                    break;
            if (j != -1) continue;

            containers[i] += nums[index];
            if (dfs(nums, containers, index + 1, target)) return true;
            containers[i] -= nums[index];
        }

        return false;
    }
};