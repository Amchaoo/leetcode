#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();
		map<int, int> map;
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			int d = target - nums[i];
			if (map.find(d) != map.end()) {
				ans.push_back(map[d]);
				ans.push_back(i);
				return ans;
			}
			map[nums[i]] = i;
		}
		return ans;
	}
};