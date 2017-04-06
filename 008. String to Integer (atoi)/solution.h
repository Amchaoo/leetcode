#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        str = trim(str);
        int base = int('0');
        long ret = 0;
        char first = str[0];
        bool positive = true;

        if (first == '+') {
            str = str.substr(1, str.length() - 1);
        }
        else if (first == '-') {
            str = str.substr(1, str.length() - 1);
            positive = false;
        }

        for (int i = 0, len = str.length(); i < len; i++) {
            int temp = int(str[i]) - base;
            if (temp < 0 || temp > 9) {
                break;
            } else {
                ret = positive ? ret * 10 + temp : ret * 10 - temp;
            }

            if (ret > INT_MAX) {
                return INT_MAX;
            }
            else if (ret < INT_MIN) {
                return INT_MIN;
            }
        }

        return ret;
    }
private:
    string trim(const string& str)
    {
        size_t first = str.find_first_not_of(' ');
        if (string::npos == first)
        {
            return str;
        }
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last - first + 1));
    }
};