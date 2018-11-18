#include <vector>
#include <iostream>
#include "solution.h";
using namespace std;

int main() {
    Solution s;
    vector<int> A = {1, 3, 6};
    int K = 3;
    cout << "result: " << s.smallestRangeI(A, K) << endl;
    return 0;
}