#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        string curWord = "";
        string reversedWords = "";
        char oneSpace = ' ';

        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == oneSpace) {
                if (curWord.empty()) continue;
                reversedWords += reversedWords.empty() ? curWord : oneSpace + curWord;
                curWord = "";
            }
            else {
                curWord = s[i] + curWord;
            }

            if (i == 0 && !curWord.empty()) {
                reversedWords += reversedWords.empty() ? curWord : oneSpace + curWord;
            }
        }

        return reversedWords;
    }
};