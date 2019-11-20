#include <string>

class Solution {
public:
    int strStr(string haystack, string needle) {
        int needleSize = needle.size();
        int haystackSize = haystack.size();

        if (needleSize == 0) {
            return 0;
        }

        if (haystackSize == 0 || haystackSize < needleSize) {
            return -1;
        }

        int leftPoint = 0;

        while (leftPoint + needleSize <= haystackSize) {
            int i = 0;

            while (i < needleSize) {
                if (needle[i] == haystack[leftPoint + i]) {
                    i++;
                }
                else {
                    break;
                }
            }

            if (i == needleSize) {
                return leftPoint;
            }
            else {
                leftPoint++;
            }
        }

        return -1;
    }
};