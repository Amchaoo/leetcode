class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> res(s.size(), 0);

        if (s.size() < 2) {
            return 0;
        }

        res[0] = 0;
        res[1] = s[0] == '(' && s[1] == ')' ? 2 : 0;
        int curMax = res[1];

        for (int i = 2; i < s.size(); i++) {
            if (s[i] == '(') {
                res[i] = 0;
            }
            else if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    res[i] = res[i - 2] + 2;
                }
                else if ((i - res[i - 1] - 1) >= 0 && s[i - res[i - 1] - 1] == '(') {
                    res[i] = res[i - 1] + 2;

                    if (i - res[i - 1] - 2 >= 0) {
                        res[i] += res[i - res[i - 1] - 2];
                    }
                }

                curMax = max(res[i], curMax);
            }
        }

        return curMax;
    }
};