#include <iostream>
#include "solution.h"

using namespace std;

int main() {
    Solution s;
    vector<int> input = {1, 1, 2};

    cout << s.removeDuplicates(input) << endl;
}