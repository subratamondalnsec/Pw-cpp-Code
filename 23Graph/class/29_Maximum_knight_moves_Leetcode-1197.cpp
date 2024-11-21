/*
code by Subrata Mondal
problem link :https://leetcode.com/problems/minimum-knight-moves/description/
*/

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;



class Solution {
public:
    int minKnightMoves(int targetX, int targetY) {
        // Adjust the target coordinates to handle negative values
        targetX += 310;
        targetY += 310;

        int steps = 0; // To count the minimum steps
        queue<pair<int, int>> knightQueue; // Queue for BFS
        knightQueue.push({310, 310}); // Starting position (shifted origin)
        vector<vector<bool>> visited(700, vector<bool>(700)); // Visited matrix
        visited[310][310] = true;

        // All possible moves for a knight
        vector<vector<int>> directions = {
            {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
            {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
        };

        // BFS to find the minimum steps
        while (!knightQueue.empty()) {
            for (int size = knightQueue.size(); size > 0; --size) {
                auto currentPosition = knightQueue.front();
                knightQueue.pop();
                int currentX = currentPosition.first;
                int currentY = currentPosition.second;

                // Check if the target is reached
                if (currentX == targetX && currentY == targetY) return steps;

                // Explore all possible moves
                for (auto& move : directions) {
                    int nextX = currentX + move[0];
                    int nextY = currentY + move[1];
                    if (!visited[nextX][nextY]) {
                        visited[nextX][nextY] = true;
                        knightQueue.push({nextX, nextY});
                    }
                }
            }
            ++steps; // Increment step count
        }
        return -1; // Return -1 if unreachable (edge case)
    }
};
int main() {
    Solution solution;
    int targetX, targetY;

    // Input target coordinates
    cout << "Enter the target X coordinate: ";
    cin >> targetX;
    cout << "Enter the target Y coordinate: ";
    cin >> targetY;

    // Output the minimum steps
    int result = solution.minKnightMoves(targetX, targetY);
    cout << "Minimum knight moves to reach (" << targetX << ", " << targetY << ") is: " << result << endl;

    return 0;
}