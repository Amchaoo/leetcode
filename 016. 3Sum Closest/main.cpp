#include <iostream>
#include <vector>
#include "solution.h"
using namespace std;

int main() {
	Solution s;
    vector<int> nums = {-3, 0, 1, 2};
    int res = s.threeSumClosest(nums, 1);

    cout<<res<<endl;
    return 0;
}