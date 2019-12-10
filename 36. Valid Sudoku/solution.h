#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int size = 9;

        for (int i = 0; i < size; i++) {
            for (int j = 0; i < size; i++) {
                if (!record(j, i, board[i][j])) {
                    return false;
                }
            }
        }

        return true;
    }
private:
    unordered_map<string, bool> recordInfo;
    bool record(int x, int y, char value) {
        if (value == '.') {
            return true;
        }

        string key = "";
        string subBoardKey = to_string(ceil(y / 3) * 3 + ceil(x / 3)) + "-" + to_string(value);
        string rowKey = "row" + to_string(y) + "-" + to_string(value);
        string colKey = "col" + to_string(x) + "-" + to_string(value);

        if (recordInfo[subBoardKey] || recordInfo[rowKey] || recordInfo[colKey]) {
            return false;
        }

        recordInfo[subBoardKey] = recordInfo[rowKey] = recordInfo[colKey] = true;
        return true;
    }
};