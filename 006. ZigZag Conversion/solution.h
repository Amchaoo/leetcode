#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        bool down = true;
        int line = 0;
        vector<string> sArr(numRows);

        if (numRows < 2) {
            return s;
        }

        for (int i = 0, len = s.length(); i < len; i++) {
            sArr[line] += s[i];
            
            if (down && line == numRows - 1) {
                down = false;
            }
            else if (!down && line == 0) {
                down = true;
            }

            down ? line++ : line--;
        }

        for (int i = 0; i < numRows; i++) {
            result += sArr[i];
        }

        return result;
    }
};