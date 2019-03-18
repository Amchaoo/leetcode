class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double result[101][101] = {0.0};
        result[0][0] = poured;

        for (int r = 0; r < 100; r++) {
            for (int c = 0; c <= r; c++) {
                if (result[r][c] > 1) {
                    result[r+1][c] += (result[r][c] - 1) / 2;
                    result[r+1][c+1] += (result[r][c] - 1) / 2;
                    result[r][c] = 1;
                }
            }
        }

        return result[query_row][query_glass];
    }
};