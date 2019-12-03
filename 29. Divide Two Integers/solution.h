#include <cmath>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool isNegative = dividend > 0 ? divisor < 0 : divisor > 0;

        long absDividend = abs(static_cast< long > (dividend));
        long absDivisor = abs(static_cast< long > (divisor));

        if (absDividend < absDivisor) {
            return 0;
        }

        long step = 1;

        while (absDivisor << 1 > 0 && absDivisor << 1 <= absDividend) {
            absDivisor <<= 1;
            step <<= 1;
        }

        long divsorCopy = absDivisor;
        long res = step;

        while (step >= 1) {
            while (absDivisor + divsorCopy <= absDividend) {
                res += step;
                absDivisor += divsorCopy;
            }

            step >>= 1;
            divsorCopy >>= 1;
        }

        if (abs(res) > INT_MAX) {
            return isNegative ? INT_MIN : INT_MAX;
        }

        return isNegative ? -res : res;
    }
};