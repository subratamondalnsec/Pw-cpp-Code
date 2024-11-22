/*
code by Subrata Mondal
problem link :https://leetcode.com/problems/walls-and-gates/description/
*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if (n == 0) return;
        int m = rooms[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Push all gates into the queue
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // Perform BFS from all gates
        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            int row=cell.first;
            int col= cell.second;
            for (int i=0;i<4;i++) {
                int newRow = row + dir[i][0];
                int newCol = col + dir[i][1];

                // Check bounds and ensure we're visiting a valid empty room
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && rooms[newRow][newCol] == INT_MAX) {
                    rooms[newRow][newCol] = rooms[row][col] + 1; // Update distance
                    q.push({newRow, newCol}); // Add the cell to the queue for further BFS
                }
            }
        }
    }
};


int main() {
    Solution solution;

    vector<vector<int>> rooms = {
        {INT_MAX, -1, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -1},
        {INT_MAX, -1, INT_MAX, -1},
        {0, -1, INT_MAX, INT_MAX}
    };

    cout << "Original Rooms:" << endl;
    for (auto& row : rooms) {
        for (int cell : row) {
            cout << (cell == INT_MAX ? "INF" : to_string(cell)) << " ";
        }
        cout << endl;
    }

    solution.wallsAndGates(rooms);

    cout << "\nUpdated Rooms:" << endl;
    for (auto& row : rooms) {
        for (int cell : row) {
            cout << (cell == INT_MAX ? "INF" : to_string(cell)) << " ";
        }
        cout << endl;
    }

    return 0;
}
