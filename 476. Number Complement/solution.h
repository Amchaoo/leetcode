#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int len = getBinaryLength(num);

        return pow(2, len) - 1 - num;
    }
private:
    int getBinaryLength(int integerValue) {
        int len = 0;
        while(integerValue != 0) {
            len++;
            integerValue /= 2;
        }

        return len;
    }
};