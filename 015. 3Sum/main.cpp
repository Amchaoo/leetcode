#include <iostream>
#include <vector>
#include "solution.h"
using namespace std;

int main() {
	Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = s.threeSum(nums);

    return 0;
}