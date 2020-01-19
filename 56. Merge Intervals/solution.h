#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sortASC(intervals);
        vector<vector<int>> res;
        int intervalsSize = intervals.size();

        if (intervalsSize == 0) {
            return intervals;
        }

        vector<int> beingPushed = intervals[0];

        for (int i = 1; i < intervalsSize; i++) {
            vector<int> currentVector = intervals[i];
            if (beingPushed[1] < currentVector[0]) {
                res.push_back(beingPushed);
                beingPushed = currentVector;
                continue;
            }

            beingPushed[0] = min(beingPushed[0], currentVector[0]);
            beingPushed[1] = max(beingPushed[1], currentVector[1]);
        }

        res.push_back(beingPushed);

        return res;
    }

private:
    static bool compare(vector<int>& x, vector<int>& y) {
        return x[0] > y[0];
    }

    void sortASC(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
    }
};