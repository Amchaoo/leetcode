#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int low = 0;
        int high = height.size() - 1;

        while (low < high) {
            maxArea = max(maxArea, (high - low) * min(height[high], height[low]));
            height[high] > height[low] ? low++ : high--;
        }

        return maxArea;
    }
};