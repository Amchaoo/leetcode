#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rowIndex = 0;
        int n = matrix.size();

        while (rowIndex < n / 2) {
            for (int i = rowIndex; i <= n - 2 - rowIndex; i++) {
                int tmp1 = matrix[rowIndex][i];
                int tmp2 = matrix[i][n - 1 - rowIndex];
                int tmp3 = matrix[n - 1 - rowIndex][n - 1 - i];
                int tmp4 = matrix[n - 1 - i][rowIndex];

                matrix[rowIndex][i] = tmp4;
                matrix[i][n - 1 - rowIndex] = tmp1;
                matrix[n - 1 - rowIndex][n - 1 - i] = tmp2;
                matrix[n - 1 - i][rowIndex] = tmp3;
            }

            rowIndex++;
        }
    }
};