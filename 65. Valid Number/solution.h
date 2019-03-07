#include <regex>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) {
            return false;
        }

        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);

        int state = 0;
        bool flag = false;

        for (int i = 0; i < s.size(); i++) {
            char currentChar = s[i];
            if (currentChar >= '0' && currentChar <= '9') {
                flag = true;

                if (state <= 2) {
                    state = 2;
                }
                else if (state > 5) {
                    state = 7;
                }
                else {
                    state = 5;
                }
            }
            else if (currentChar == '.') {
                if (state <= 2) {
                    state = 6;
                }
                else {
                    return false;
                }
            }
            else if (currentChar == 'e') {
                if (flag && (state == 2 || state == 6 || state == 7)) {
                    state= 3;
                }
                else {
                    return false;
                }
            }
            else if (currentChar == '+' || currentChar == '-') {
                if (state == 0) {
                    state = 1;
                }
                else if (state == 3) {
                    state = 4;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }

        return state == 2 || state == 5 || (flag && state == 6) || state == 7;
    }
};