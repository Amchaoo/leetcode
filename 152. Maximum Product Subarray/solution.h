class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        // 表示以第i位为结尾的最大子数组乘积
        vector<int> f(nums.size(), 0);
        vector<int> m(nums.size(), 0);
        f[0] = nums[0];
        m[0] = nums[0];
        int curMax = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            f[i] = max(max(m[i - 1] * nums[i], f[i - 1] * nums[i]), nums[i]);
            m[i] = min(min(m[i - 1] * nums[i], f[i - 1] * nums[i]), nums[i]);
            curMax = max(f[i], curMax);
        }

        return curMax;
    }
};