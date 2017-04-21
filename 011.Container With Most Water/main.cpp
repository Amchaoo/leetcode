#include "solution.h"
#include <vector>

void main() {
    Solution s;
    int n[] = { 1, 1 };
    vector<int> height(n, n + 2);

    int maxArea = s.maxArea(height);
}