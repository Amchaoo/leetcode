#include <math.h> 

class Solution {
public:
    int reverse(int x) {
        long ret = 0;
        while (x) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }

        if (ret > upRange || ret < downRange) {
            return 0;
        }

        return ret;
    }

private:
    int upRange = pow(2, 31) - 1;
    int downRange = -upRange - 1;
};