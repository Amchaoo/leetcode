#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();

        if (m == 0) {
            return 0;
        }

        n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfsMark(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }

private:
    int m = 0;
    int n = 0;

    void dfsMark(vector<vector<char>>& grid, int i, int j) {
        if (i >= m || j >= n || i < 0 || j < 0 || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';
        dfsMark(grid, i - 1, j);
        dfsMark(grid, i + 1, j);
        dfsMark(grid, i, j - 1);
        dfsMark(grid, i, j + 1);
    }
};