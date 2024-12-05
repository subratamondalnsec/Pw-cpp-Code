/*
code by Subrata Mondal
problem link : https://leetcode.com/problems/detect-cycles-in-2d-grid/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Directions for neighbors

    bool dfs(int row, int col, int parentRow, int parentCol, vector<vector<int>>& visited, vector<vector<char>>& grid) {
        visited[row][col] = 1; // Mark the cell as visited
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + dir[i][0];
            int ncol = col + dir[i][1];

            // Check bounds and Check if the character matches the current cell's character
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == grid[row][col]) {
                // If already visited and not the parent, cycle detected
                if (visited[nrow][ncol] == 1) {
                    if (nrow != parentRow || ncol != parentCol) {
                        return true;
                    }
                } 
                // If not visited, continue DFS
                else {
                    if (dfs(nrow, ncol, row, col, visited, grid)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0)); // Visited array

        // Start DFS for every unvisited cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, visited, grid)) {
                        return true; // Cycle detected
                    }
                }
            }
        }
        return false; // No cycle found
    }
};


int main() {
    Solution solution;

    // Test Case 1: Grid with a cycle
    vector<vector<char>> grid1 = {
        {'a', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'a', 'a', 'a'}
    };
    cout << "Test Case 1: " << (solution.containsCycle(grid1) ? "true" : "false") << endl; // Expected: true

    // Test Case 2: Grid without a cycle
    vector<vector<char>> grid2 = {
        {'a', 'b', 'b'},
        {'b', 'z', 'b'},
        {'b', 'b', 'a'}
    };
    cout << "Test Case 2: " << (solution.containsCycle(grid2) ? "true" : "false") << endl; // Expected: false

    // Test Case 3: Small Grid with a cycle
    vector<vector<char>> grid3 = {
        {'a', 'a'},
        {'a', 'a'}
    };
    cout << "Test Case 3: " << (solution.containsCycle(grid3) ? "true" : "false") << endl; // Expected: true

    // Test Case 4: Single Row Grid
    vector<vector<char>> grid4 = {
        {'a', 'b', 'c', 'd'}
    };
    cout << "Test Case 4: " << (solution.containsCycle(grid4) ? "true" : "false") << endl; // Expected: false

    // Test Case 5: Single Column Grid
    vector<vector<char>> grid5 = {
        {'a'},
        {'b'},
        {'c'},
        {'d'}
    };
    cout << "Test Case 5: " << (solution.containsCycle(grid5) ? "true" : "false") << endl; // Expected: false

    return 0;
}