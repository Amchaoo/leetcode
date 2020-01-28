#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);
        visited = vector(numCourses, 0);

        for (auto prerequisite: prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }

        while (--numCourses >= 0) {
            if (!learn(numCourses)) {
                return false;
            }
        }

        return true;
    }

private:
    vector<vector<int>> graph;
    vector<int> visited;

    bool learn(int courseId) {
        if (visited[courseId] == 1) {
            return false;
        }

        if (visited[courseId] == 2) {
            return true;
        }

        visited[courseId] = 1;

        for (auto course: graph[courseId]) {
            if (!learn(course)) {
                return false;
            }
        }

        visited[courseId] = 2;
        return true;
    }
};