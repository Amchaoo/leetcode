#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mapping{ {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int result = mapping[s.back()];

        for (int i = s.size() - 2; i >= 0; i--) {
            int prev = mapping[s[i]];
            int next = mapping[s[i + 1]];

            result += prev >= next ? prev : -prev;
        }

        return result;
    }
};