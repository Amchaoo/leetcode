#include <iostream>
#include <vector>
#include "solution.h"
using namespace std;

int main() {
    Solution s;
    vector<string> res = s.generateParenthesis(3);

    cout << "input: \n3" << endl;
    cout << "output:" << endl;

    for (vector<string>::iterator i = res.begin(); i != res.end(); i++) {
        cout << *i << endl;
    }

    return 0;
}