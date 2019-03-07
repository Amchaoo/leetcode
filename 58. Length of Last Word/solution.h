using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int stringSize = s.size();
        bool meetWord = false;
        int len = 0;

        while (stringSize--) {
            if (s[stringSize] != ' ') {
                meetWord = true;
                len++;
            }
            else if (!meetWord) {
                continue;
            }
            else {
                break;
            }
        }

        return len;
    }
};