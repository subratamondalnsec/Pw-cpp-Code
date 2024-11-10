/*
code by Subrata Mondal
problem link : https://leetcode.com/problems/keys-and-rooms/
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visit;
        queue<int> q;
        visit.insert(0);
        q.push(0);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : rooms[node]) {
                if (visit.count(neighbor) == 0) {
                    q.push(neighbor);
                    visit.insert(neighbor);
                }
            }
        }
        
        return (rooms.size() == visit.size());
    }
};

int main() {
    Solution solution;
    
    // Define example test cases
    vector<vector<int>> rooms1 = {{1}, {2}, {3}, {}};
    vector<vector<int>> rooms2 = {{1,3}, {3,0,1}, {2}, {0}};
    
    // Test case 1
    bool result1 = solution.canVisitAllRooms(rooms1);
    cout << "Can visit all rooms in test case 1: " << (result1 ? "Yes" : "No") << endl;

    // Test case 2
    bool result2 = solution.canVisitAllRooms(rooms2);
    cout << "Can visit all rooms in test case 2: " << (result2 ? "Yes" : "No") << endl;
    
    return 0;
}
