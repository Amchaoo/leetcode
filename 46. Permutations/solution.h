#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        map<int, bool> visitRecord;
        vector<int> current;
        vector<vector<int>> permutations;
        find(permutations, nums, current, visitRecord);

        return permutations;
    }

private:
    void find(vector<vector<int>>& permutations, vector<int>& nums, vector<int>& current, map<int, bool>& visitedRecord) {
        int numsSize = nums.size();

        if (numsSize == current.size()) {
            permutations.push_back(current);
            return;
        }

        for (int i = 0; i < numsSize; i++) {
            if (visitedRecord[i]) {
                continue;
            }

            visitedRecord[i] = true;
            current.push_back(nums[i]);
            find(permutations, nums, current, visitedRecord);
            visitedRecord[i] = false;
            current.pop_back();
        }
    }
};