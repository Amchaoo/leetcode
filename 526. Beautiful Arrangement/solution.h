#include <iostream>

using namespace std;

class Solution {
public:
    int count = 0;
    int countArrangement(int N) {
        countFun(new int[N + 1](), N, 1);
        return count;
    }

    void countFun(int *used, int N, int curPos) {
        if (curPos > N) {
            count++;
            return;
        }

        for (int i = 1; i <= N; i++) {
            if (used[i] == 0 && (curPos % i == 0 || i % curPos == 0)) {
                used[i] = 1;
                countFun(used, N, curPos + 1);
                used[i] = 0;
            }
        }
    }
};