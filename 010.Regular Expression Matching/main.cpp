#include "solution.h"
#include <string>
using namespace std;

int main() {
    RecSolution r;
    DpSolution d;
    string s = "aab";
	string p = "c*a*b**";

    bool matchRes = r.isMatch(s, p);
    bool dRes = d.isMatch(s, p);

    return 0;
}