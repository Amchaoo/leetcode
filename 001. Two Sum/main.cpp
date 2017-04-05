#include <iostream>
#include <vector>
#include "solution.h"
using namespace std;
int main() {
	
    Solution s;
    vector <int> nums = { 1, 2, 3, 4, 5 };
    vector <int> res = s.twoSum(nums, 5);

    for (auto val : res)
    {
        cout << val << endl;
    }

<<<<<<< HEAD
    return 0;
}
=======
	return 0;
}
>>>>>>> f61d19231778311a98f8738c92483ae2582dc7c2
