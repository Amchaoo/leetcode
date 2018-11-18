#include <vector>
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int size = A.size();

        if (size <= 1) {
            return 0;
        }

        int min = A[0], max = A[0];

        for (int i = 1; i < size; i++) {
            if (A[i] < min) {
                min = A[i];
            }
            else if (A[i] > max) {
                max = A[i];
            }
        }

        int subValue = max - min;

        if (subValue > 2 * K) {
            return subValue - 2 * K;
        }
        else {
            return 0;
        }
    }
};