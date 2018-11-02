#include <iostream>
#include "solution.h"
using namespace std;

int main() {
	Solution s;

    vector<int> arr = {-3,-2,-1,0,0,1,2,3};
    vector<vector<int>> res = s.fourSum(arr, 0);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j ++) {
            cout << res[i][j];
        }
    }
    return 0;
}