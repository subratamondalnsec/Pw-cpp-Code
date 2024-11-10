/*
code by Subrata Mondal
problem link : https://leetcode.com/problems/find-center-of-star-graph/
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0];
        int b = edges[0][1];
        int c = edges[1][0];
        int d = edges[1][1];
        return (c == a || c == b) ? c : d;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
    int center = solution.findCenter(edges);
    cout << "The center of the star graph is: " << center << endl;
    return 0;
}
