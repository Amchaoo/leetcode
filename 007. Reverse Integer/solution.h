#include <math.h> 

class Solution {
public:
    int reverse(int x) {
		if (x > upRange || x < downRange) {
			return 0;
		}
        int ret = 0;
		while (x) {
			ret = ret * 10 + x % 10;
			x /= 10;
		}
		return ret;
    }

private:
	int upRange = pow(2, 31) - 1;
	int downRange = -upRange - 1;
};