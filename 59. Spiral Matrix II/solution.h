#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int circleCount = ceil(n / 2),
            circleIndex = 0,
            x = 0,
            y = 0,
            index = 0;
        vector<vector<int>> res(n, vector<int>(n));

        while (circleIndex <= circleCount) {
            // 向右
            while (y <= n - 1 - circleIndex * 2) {
                res[x][y++] = index++;
            }
            y--;

            // 向下
            while (x <= n - 1 - circleIndex * 2) {
                res[++x][y] = index++;
            }
            x--;

            // 向左
            while (y >= circleIndex) {
                res[x][--y] = index++;
            }
            y++;

            // 向上
            while (x > circleIndex) {
                res[--x][y] = index++;
            }
            x++;

            y++;
            circleIndex++;
        }

        return res;
    }
};