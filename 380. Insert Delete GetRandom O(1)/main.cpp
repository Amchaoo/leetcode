#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    RandomizedSet r;

    // cout << r.insert(1) << endl;
    // cout << r.insert(2) << endl;
    // cout << r.getRandom() << endl;
    // cout << r.remove(1) << endl;
    r.insert(3);
    r.insert(-2);
    r.remove(2);
    r.insert(1);
    r.insert(-3);
    r.insert(-2);
    r.remove(-2);
    r.remove(3);
    r.insert(-1);
    r.remove(-3);

    return 0;
}