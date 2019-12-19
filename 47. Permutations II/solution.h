#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, bool> visitRecord;
        vector<int> current;
        vector<vector<int>> permutations;
        find(permutations, nums, current, visitRecord);

        return permutations;
    }

private:
    void find(vector<vector<int>>& permutations, vector<int>& nums, vector<int>& current, map<int, bool>& visitedIndexRecord) {
        int numsSize = nums.size();
        map<int, bool> visitedValueRecord;

        if (numsSize == current.size()) {
            permutations.push_back(current);

            return;
        }

        for (int i = 0; i < numsSize; i++) {
            if (visitedIndexRecord[i] || visitedValueRecord[nums[i]]) {
                continue;
            }

            visitedIndexRecord[i] = true;
            visitedValueRecord[nums[i]] = true;
            current.push_back(nums[i]);
            find(permutations, nums, current, visitedIndexRecord);
            visitedIndexRecord[i] = false;
            current.pop_back();
        }
    }
};