#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    map<int, string> cache;

    Solution() {
        cache.insert(make_pair(1, "1"));
    }

    string countAndSay(int n) {
        if (cache.find(n) != cache.end()) {
            return cache[n];
        }

        string res = sayString(countAndSay(n - 1));
        cache[n] = res;

        return res;
    }

    string sayString(string str) {
        char curChar = '#';
        int curCount = 0;
        string result = "";

        for (int i = 0; i < str.size(); i++) {
            if (curChar == str[i]) {
                curCount++;
            }
            else {
                if (curChar != '#') {
                    result += to_string(curCount) + curChar;
                }

                curChar = str[i];
                curCount = 1;
            }
        }
        result += to_string(curCount) + curChar;
        return result;
    }
};