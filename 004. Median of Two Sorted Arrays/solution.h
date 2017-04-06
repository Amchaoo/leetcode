#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(),
            len2 = nums2.size(),
            prev = 0,
            now = 0,
            medianLoc = (len1 + len2) / 2;
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);

        for (int i = 0; i <= medianLoc; i++) {
            if (nums1.at(0) < nums2.at(0)) {
                prev = now;
                now = nums1.front();
                nums1.erase(nums1.begin());
            }
            else {
                prev = now;
                now = nums2.front();
                nums2.erase(nums2.begin());
            }
        }

        return (len1 + len2) % 2 == 0 ? (double)(prev + now) / 2 : (double)now;
    }
};