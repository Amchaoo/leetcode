#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    map<int, int> factorialMemory;

    Solution() {
        factorialMemory[1] = 1;

        for (int i = 2; i <= 8; i++) {
            factorialMemory[i] = factorialMemory[i - 1] * i;
        }
    }

    string getPermutation(int n, int k) {
        map<int, bool> usedDigit;
        int currentDigitIndex = 0;
        int layer = 0;
        string permutaion = "";
        k -= 1;

        while (layer < n) {
            currentDigitIndex = ceil(k / factorialMemory[n - layer]);
            k = k % factorialMemory[n - layer];

            int i = 1;
            while (true) {
                if (usedDigit[i]) {
                    i++;
                    continue;
                }

                currentDigitIndex--;

                if (currentDigitIndex == 0) {
                    usedDigit[i] = true;
                    permutaion += to_string(i);
                    break;
                }
            }

            layer++;
        }

        return permutaion;
    }
};