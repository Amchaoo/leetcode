#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int len = height.size();

        for (int i = 1; i < len; i++) {
            int j = i;
            while (++j < len) {
                int area = 2 * min(height[i], height[j]);
                maxArea = area > maxArea ? area : maxArea;
            }
        }

        return maxArea;
    }
};