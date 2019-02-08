#include <vector>
#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    Solution s;
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};
    int K = 3;
    cout << "result: " << s.mincostTickets(days, costs) << endl;
    return 0;
}