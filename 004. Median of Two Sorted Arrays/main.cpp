#include <vector>
#include "solution.h"

using namespace std;

int main() {
    Solution s;
    vector<int> nums1 = { 1, 2 };
    vector<int> nums2 = { 1 };

    double result = s.findMedianSortedArrays(nums1, nums2);
    return 0;
}