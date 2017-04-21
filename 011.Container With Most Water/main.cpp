#include "solution.h"
#include <vector>

void main() {
    Solution s;
    int n[] = { 2, 5, 6, 1 };
    vector<int> height(n, n + 4);

    int maxArea = s.maxArea(height);
}