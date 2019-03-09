#include <iostream>
#include <vector>
#include "solution.h"
using namespace std;

int main() {
    Solution s;
    vector<vector<int>> input = {
        {7},
        {9},
        {6}
    };

    vector<int> res = s.spiralOrder(input);

    cout << "output:" << endl;

    for (vector<int>::iterator i = res.begin(); i != res.end(); i++) {
        cout << *i << endl;
    }

    return 0;
}