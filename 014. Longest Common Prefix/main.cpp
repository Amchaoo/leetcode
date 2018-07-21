#include <iostream>
#include <vector>
#include "solution.h"
using namespace std;
int main() {
	Solution s;
    vector <string> strs = {"c","c","c"};
    string res = s.longestCommonPrefix(strs);

    cout << res << endl;
    return 0;
}