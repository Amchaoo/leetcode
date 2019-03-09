#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int circle = 0;
        vector<int> res = {};

        int height = matrix.size();

        if (height == 0) {
            return res;
        }

        int width = matrix[0].size();

        if (width == 0) {
            return res;
        }

        while(circle < (ceil(min(width, height) / static_cast<double>(2)))) {
            bool hasMoveRight = false, hasMoveDown = false;
            int xPos = circle, yPos = circle;

            res.push_back(matrix[yPos][xPos]);

            // right
            while (++xPos <= width - circle - 1) {
                hasMoveRight = true;
                res.push_back(matrix[yPos][xPos]);
            }

            xPos--;

            // down
            while (++yPos <= height - circle - 1) {
                hasMoveDown = true;
                res.push_back(matrix[yPos][xPos]);
            }

            yPos--;

            // left
            while (hasMoveRight && hasMoveDown && --xPos >= circle) {
                res.push_back(matrix[yPos][xPos]);
            }

            xPos++;

            // top
            while (hasMoveRight && hasMoveDown && --yPos >= (circle + 1)) {
                res.push_back(matrix[yPos][xPos]);
            }

            circle++;
        }

        return res;
    }
};