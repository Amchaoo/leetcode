#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) {
            return s;
        }

        int left, right, maxLeft = 0, maxLen = 1,
            start = 0, len = s.size();

        while (start < len - 1) {
            left = right = start;

            while (right < len && s[right] == s[right + 1]) {
                right++;
            }
            
            start = right + 1;

            while (right < len - 1 && left > 0 && s[left - 1] == s[right + 1]) {
                right++;
                left--;
            }

            if (maxLen < right - left + 1) {
                maxLeft = left;
                maxLen = right - left + 1;
            }
        }

        return s.substr(maxLeft, maxLen);
    }
};