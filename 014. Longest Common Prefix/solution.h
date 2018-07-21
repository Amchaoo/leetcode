#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        int maxIndex = getShortestLen(strs);
        int len = strs.size();
        bool isCommon = true;

        if (len == 0) {
            return "";
        } else if (len == 1) {
            return strs[0];
        }

        while (isCommon) {
            char ch = strs[0][index];
            for (int i = 1; i < len; i++) {
                if (strs[i][index] == ch) {
                    continue;
                }
                
                isCommon = false;
                index--;
                break;
            }

            if (index + 1 == maxIndex) {
                break;
            }

            if (isCommon) {
                index++;
            }
        }

        return strs[0].substr(0, index + 1);
    }
private:
    int getShortestLen(vector<string>& strs) {
        int size = strs.size();
        if (size == 0) {
            return 0;
        }

        int shortestLen = strs[1].size();

        for (int i = 1; i < size; i++) {
            if (shortestLen > strs[i].size()) {
                shortestLen = strs[i].size();
            }
        }

        return shortestLen;
    }
};