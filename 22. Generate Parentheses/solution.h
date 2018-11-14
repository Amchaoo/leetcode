#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, "", n, n);

        return result;
    }

    int generate(vector<string> &v, string str, int l, int r) {
        if (l == 0 && r == 0) {
            v.push_back(str);
        }

        if (l > 0) {
            generate(v, str + "(", l - 1, r);
        }
        if (r > l) {
            generate(v, str + ")", l, r - 1);
        }

        return 0;
    }
};