#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    Solution();
    vector<string> letterCombinations(string digits) {
        vector<string> res = valueMap[digits[0]];
        int digitsSize = digits.size();
        for (int i = 1; i < digitsSize; i++) {
            res = twoLetterCombinations(res, valueMap[digits[i]]);
        }

        return res;
    }
private:
    map<char, vector<string>> valueMap;
    vector<string> twoLetterCombinations(vector<string>& str1, vector<string>& str2) {
        vector<string> res = {};
        int str1Size = str1.size();
        int str2Size = str2.size();

        for (int i = 0; i < str1Size; i++) {
            for (int j = 0; j < str2Size; j++) {
                res.push_back(str1[i] + str2[j]);
            }
        }

        return res;
    }
};

Solution::Solution() {
    valueMap['2'] = {"a", "b", "c"};
    valueMap['3'] = {"d", "e", "f"};
    valueMap['4'] = {"g", "h", "i"};
    valueMap['5'] = {"j", "k", "l"};
    valueMap['6'] = {"m", "n", "o"};
    valueMap['7'] = {"p", "q", "r", "s"};
    valueMap['8'] = {"t", "u", "v"};
    valueMap['9'] = {"w", "x", "y", "z"};
}