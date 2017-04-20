#include "solution.h"
#include <string>
using namespace std;

int main() {
	RecSolution s;
	string s = "aab";
	string p = "c*a*b";

	bool matchRes = s.isMatch(s, p);

	return 0;
}