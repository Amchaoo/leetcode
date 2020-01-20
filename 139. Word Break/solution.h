/**
 * 设状态 f(x) 表示 长度前x的字符串是否有wordBreak
 * 状态转移方程:
 * 对于 a < 1, 则有
 * f(x) = f(a) && wordDict.includes(s.substr(a, x));
 */
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> f(s.size());
        f[0] = true;

        for (int i = 0; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (
                    f[j]
                    && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()
                ) {
                    f[i] = true;
                    break;
                }
            }
        }

        return f[s.size()];
    }
};