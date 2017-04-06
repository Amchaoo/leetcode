#include <string>
#include <algorithm> 
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> charMap;
        int maxLen = 0;
        int start = -1;

        for (int i = 0, len = s.length(); i < len; i++) {
            char item = s[i];
            if (charMap.find(item) != charMap.end()) {
                start = max(start, charMap[item]);
            }

            maxLen = max(maxLen, i - start);
            charMap[item] = i;
        }

        return maxLen;
    }
};