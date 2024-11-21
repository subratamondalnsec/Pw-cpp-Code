/*
code by Subrata Mondal
problem link :https://www.geeksforgeeks.org/problems/steps-by-knight5927/1
same as leetcode 1197
*/

#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

class Solution{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
        if (KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1]) 
            return 0;

        // Directions for Knight's movement
        int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
        int dy[8] = {2, 1, -2, -1, 2, 1, -2, -1};

        // Visited matrix to prevent revisiting
        vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
        queue<pair<pair<int, int>, int>> q; // {{row, col}, steps}

        // Starting position
        q.push({{KnightPos[0], KnightPos[1]}, 0});
        visited[KnightPos[0]][KnightPos[1]] = true;

        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            int row = cell.first.first;
            int col = cell.first.second;
            int level = cell.second;

            for (int i = 0; i < 8; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];

                // Check if the new position is within bounds
                if (nr >= 1 && nc >= 1 && nr <= N && nc <= N && !visited[nr][nc]) {
                    // Check if target position is reached
                    if (nr == TargetPos[0] && nc == TargetPos[1]) 
                        return level + 1;

                    // Mark as visited and add to queue
                    visited[nr][nc] = true;
                    q.push({{nr, nc}, level + 1});
                }
            }
        }
        return -1; // If target is not reachable (edge case)
    }
};


class Solution {
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){
	   if (N <= 0) return -1; // Invalid chessboard size
        if (KnightPos[0] < 1 || KnightPos[1] < 1 || KnightPos[0] > N || KnightPos[1] > N ||
            TargetPos[0] < 1 || TargetPos[1] < 1 || TargetPos[0] > N || TargetPos[1] > N) {
            return -1; // Invalid positions
        }
        if (KnightPos == TargetPos) return 0; // Already at target

        // Directions for Knight's movement
        int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
        int dy[8] = {2, 1, -2, -1, 2, 1, -2, -1};

        // Visited set to prevent revisiting
        set<pair<int, int>> visited;
        queue<pair<pair<int, int>, int>> q; // {{row, col}, steps}

        // Starting position
        q.push({{KnightPos[0], KnightPos[1]}, 0});
        visited.insert({KnightPos[0], KnightPos[1]});

        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            int row = cell.first.first;
            int col = cell.first.second;
            int level = cell.second;

            for (int i = 0; i < 8; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];

                // Check if the new position is within bounds
                if (nr >= 1 && nc >= 1 && nr <= N && nc <= N && visited.find({nr, nc}) == visited.end()) {
                    // Check if target position is reached
                    if (nr == TargetPos[0] && nc == TargetPos[1]) 
                        return level + 1;

                    // Mark as visited and add to queue
                    visited.insert({nr, nc});
                    q.push({{nr, nc}, level + 1});
                }
            }
        }
        return -1; 
	}
};

int main() {
    // Initialize the knight's position and target position
    vector<int> KnightPos = {4, 5};  // Example: Knight starts at (4, 5)
    vector<int> TargetPos = {1, 1}; // Example: Target position is (1, 1)
    int N = 6;                      // Example: Chessboard size (N x N)

    // Create an object of the Solution class
    Solution obj;

    // Call the function and store the result
    int steps = obj.minStepToReachTarget(KnightPos, TargetPos, N);

    // Output the result
    if (steps == -1) {
        cout << "Invalid input or target is not reachable." << endl;
    } else {
        cout << "Minimum steps to reach the target: " << steps << endl;
    }

    return 0;
}
