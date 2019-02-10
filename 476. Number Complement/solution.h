#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int numCopy = num;
        int len = 0;

        while(numCopy != 0) {
            numCopy >>= 1;
            len++;
        }

        return pow(2, len) - 1 - num;
    }
};